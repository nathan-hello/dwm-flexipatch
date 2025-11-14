package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
)

// ConditionalState tracks the state of a conditional block
type ConditionalState struct {
	condition string        // The condition being tested (e.g., "ROUNDED_CORNERS_PATCH")
	isTrue    bool          // Whether the condition evaluated to true
	inElse    bool          // Whether we're in an else branch
	depth     int           // Nesting depth
}

// processConfigFile processes config.def.h and generates config.minimal.h
func processConfigFile(inputPath string, patches map[string]bool, macros map[string]string, outputPath string) error {
	inputFile, err := os.Open(inputPath)
	if err != nil {
		return err
	}
	defer inputFile.Close()

	// First pass: read all lines
	var lines []string
	scanner := bufio.NewScanner(inputFile)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		return err
	}

	outputFile, err := os.Create(outputPath)
	if err != nil {
		return err
	}
	defer outputFile.Close()

	processor := &ConfigProcessor{
		patches:    patches,
		macros:     macros,
		output:     outputFile,
		lines:      lines,
		currentIdx: 0,
		lineNumber: 0,
	}

	for processor.currentIdx = 0; processor.currentIdx < len(lines); processor.currentIdx++ {
		processor.lineNumber = processor.currentIdx + 1
		if err := processor.processLine(lines[processor.currentIdx]); err != nil {
			return fmt.Errorf("line %d: %w", processor.lineNumber, err)
		}
	}

	// Check for unclosed conditionals
	if len(processor.stack) > 0 {
		return fmt.Errorf("unclosed conditional blocks: %d blocks still open", len(processor.stack))
	}

	return nil
}

// ConfigProcessor handles the processing of config.def.h
type ConfigProcessor struct {
	patches    map[string]bool     // Evaluated patches
	macros     map[string]string   // CONFIG_* macros
	output     *os.File            // Output file
	stack      []ConditionalState  // Stack of conditional states
	lineNumber int                 // Current line number
	lines      []string            // All input lines
	currentIdx int                 // Current line index
}

// processLine processes a single line from config.def.h
func (cp *ConfigProcessor) processLine(line string) error {
	trimmed := strings.TrimSpace(line)

	// Handle preprocessor directives
	if strings.HasPrefix(trimmed, "#if ") {
		return cp.handleIfBlock()
	}
	if strings.HasPrefix(trimmed, "#elif ") || strings.HasPrefix(trimmed, "#else") || strings.HasPrefix(trimmed, "#endif") {
		// These should have been consumed by handleIfBlock, skip them
		return nil
	}

	// Process regular content
	if cp.isInActiveBranch() {
		return cp.processContent(line)
	}

	return nil
}

// isInActiveBranch determines if the current line should be output
func (cp *ConfigProcessor) isInActiveBranch() bool {
	if len(cp.stack) == 0 {
		return true // Top level, always active
	}

	// Check the topmost state - we're active if all ancestors are active
	for _, state := range cp.stack {
		if !state.isTrue {
			return false
		}
	}
	return true
}

// handleIfBlock processes an entire #if...#endif block as a unit
func (cp *ConfigProcessor) handleIfBlock() error {
	trimmed := strings.TrimSpace(cp.lines[cp.currentIdx])

	// Extract condition: #if CONDITION
	condition := strings.TrimPrefix(trimmed, "#if ")
	condition = strings.TrimSpace(condition)

	// Evaluate the condition
	value, err := evaluateExpression(condition, cp.patches)
	if err != nil {
		return fmt.Errorf("cannot evaluate condition '%s': %w", condition, err)
	}

	// Find the matching #endif and extract block content
	endifIdx, branches, err := cp.parseConditionalBlock(cp.currentIdx, condition)
	if err != nil {
		return err
	}

	// Process based on whether condition is true
	if value {
		// Output the if-content
		cp.writeLine(cp.lines[cp.currentIdx]) // #if directive
		for _, line := range branches["if"] {
			if err := cp.processContent(line); err != nil {
				return err
			}
		}
		cp.writeLine(cp.lines[endifIdx]) // #endif directive
	} else if _, hasElse := branches["else"]; hasElse {
		// Output the else-content without the conditional
		for _, line := range branches["else"] {
			if err := cp.processContent(line); err != nil {
				return err
			}
		}
	}
	// If no else and condition is false, skip the entire block

	// Skip to the endif
	cp.currentIdx = endifIdx

	return nil
}

// parseConditionalBlock parses an #if block and returns the endif index and content branches
func (cp *ConfigProcessor) parseConditionalBlock(startIdx int, condition string) (int, map[string][]string, error) {
	branches := make(map[string][]string)
	currentBranch := "if"
	nesting := 0

	for i := startIdx + 1; i < len(cp.lines); i++ {
		trimmed := strings.TrimSpace(cp.lines[i])

		// Handle nesting
		if strings.HasPrefix(trimmed, "#if ") {
			nesting++
			branches[currentBranch] = append(branches[currentBranch], cp.lines[i])
		} else if strings.HasPrefix(trimmed, "#endif") {
			if nesting == 0 {
				// Found our endif
				return i, branches, nil
			}
			nesting--
			branches[currentBranch] = append(branches[currentBranch], cp.lines[i])
		} else if strings.HasPrefix(trimmed, "#elif ") && nesting == 0 {
			// elif at our level - skip (we don't support elif chains for now)
			currentBranch = "elif"
		} else if strings.HasPrefix(trimmed, "#else") && nesting == 0 {
			// else at our level
			currentBranch = "else"
		} else {
			// Regular content line
			branches[currentBranch] = append(branches[currentBranch], cp.lines[i])
		}
	}

	return -1, branches, fmt.Errorf("no matching #endif for #if at line %d", startIdx+1)
}

// processContent processes a non-directive line
func (cp *ConfigProcessor) processContent(line string) error {
	trimmed := strings.TrimSpace(line)

	// Skip conditional directives (these are handled separately)
	if strings.HasPrefix(trimmed, "#if ") || strings.HasPrefix(trimmed, "#elif ") ||
		strings.HasPrefix(trimmed, "#else") || strings.HasPrefix(trimmed, "#endif") {
		return nil
	}

	// Check if line contains a CONFIG_* macro to expand
	if strings.Contains(trimmed, "CONFIG_") {
		return cp.expandMacros(line)
	}

	// Regular line (including non-conditional preprocessor directives), just output it
	cp.writeLine(line)
	return nil
}

// expandMacros expands CONFIG_* macros in a line
func (cp *ConfigProcessor) expandMacros(line string) error {
	trimmed := strings.TrimSpace(line)

	// Find all CONFIG_* macros in the line
	re := regexp.MustCompile(`CONFIG_[A-Z_][A-Z0-9_]*`)
	matches := re.FindAllString(trimmed, -1)

	// Check if we have exactly one macro (common case)
	if len(matches) == 1 {
		macroName := matches[0]
		if macro, exists := cp.macros[macroName]; exists {
			// Get indentation from original line
			indent := getIndentation(line)
			// Expand the macro with proper indentation
			cp.writeIndentedMacro(indent, macro)
			return nil
		} else {
			return fmt.Errorf("CONFIG_* macro not found: %s", macroName)
		}
	}

	// Multiple macros in one line - expand them all
	result := line
	for _, macroName := range matches {
		if macro, exists := cp.macros[macroName]; exists {
			// Simple replacement for multiple macros on one line
			result = strings.ReplaceAll(result, macroName, macro)
		} else {
			return fmt.Errorf("CONFIG_* macro not found: %s", macroName)
		}
	}
	cp.writeLine(result)
	return nil
}

// getIndentation extracts the leading whitespace from a line
func getIndentation(line string) string {
	for i, ch := range line {
		if ch != ' ' && ch != '\t' {
			return line[:i]
		}
	}
	return line
}

// writeIndentedMacro writes a macro expansion with proper indentation
func (cp *ConfigProcessor) writeIndentedMacro(indent string, macro string) {
	lines := strings.Split(macro, "\n")
	for _, line := range lines {
		if strings.TrimSpace(line) == "" {
			cp.writeLine("")
		} else {
			cp.writeLine(indent + line)
		}
	}
}

// writeLine writes a line to the output file
func (cp *ConfigProcessor) writeLine(line string) {
	fmt.Fprintln(cp.output, line)
}
