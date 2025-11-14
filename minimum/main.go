package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
)

// PatchConfig holds the state of which patches are enabled
type PatchConfig struct {
	EnabledPatches map[string]bool // true if patch is enabled, false if disabled, absent if not a patch
	AllPatches     map[string]bool // all patches we know about (for distinguishing from other #if identifiers)
}

func main() {
	// Command-line flags
	configFile := flag.String("config", "../config.def.h", "Path to source config.def.h")
	patchesFile := flag.String("patches", "../patches.h", "Path to patches.h defining enabled patches")
	outputFile := flag.String("output", "config.min.h", "Path to output minimal config.def.h")
	flag.Parse()

	// Parse enabled patches
	patches, err := parsePatches(*patchesFile)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error parsing patches: %v\n", err)
		os.Exit(1)
	}

	fmt.Printf("Found %d enabled patches:\n", len(patches.EnabledPatches))
	// Sort and print enabled patches for consistent output
	var enabledPatchNames []string
	for name := range patches.EnabledPatches {
		enabledPatchNames = append(enabledPatchNames, name)
	}
	sort.Strings(enabledPatchNames)
	for _, name := range enabledPatchNames {
		fmt.Printf("  ✓ %s\n", name)
	}
	fmt.Println()

	// Generate minimal config
	err = patches.generateMinimalConfig(*configFile, *outputFile)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error generating minimal config: %v\n", err)
		os.Exit(1)
	}

	fmt.Printf("✓ Generated minimal config: %s\n", *outputFile)
}

// parsePatches reads a patches.h file and extracts enabled patch names
// Format: #define PATCH_NAME <value>
// Tracks both enabled (1) and disabled (0) patches
func parsePatches(patchPath string) (*PatchConfig, error) {
	patches := &PatchConfig{
		EnabledPatches: make(map[string]bool),
		AllPatches:     make(map[string]bool),
	}

	file, err := os.Open(patchPath)
	if err != nil {
		// If patches.h doesn't exist, return empty set (all patches disabled)
		fmt.Printf("Warning: Could not open %s, assuming no patches enabled: %v\n", patchPath, err)
		return patches, nil
	}
	defer file.Close()

	// Match lines like: #define PATCH_NAME <value>
	defineRegex := regexp.MustCompile(`^\s*#define\s+(\w+)\s+(.+)$`)

	// Store raw values first
	rawValues := make(map[string]string)

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		matches := defineRegex.FindStringSubmatch(line)
		if len(matches) >= 3 {
			patchName := matches[1]
			value := strings.TrimSpace(matches[2])

			// Track this as a known patch
			patches.AllPatches[patchName] = true
			rawValues[patchName] = value
		}
	}

	// Now evaluate each patch (resolves dependencies and expressions)
	evalCache := make(map[string]bool)
	for patchName := range patches.AllPatches {
		if evaluatePatch(patchName, rawValues, evalCache) {
			patches.EnabledPatches[patchName] = true
		}
	}

	return patches, scanner.Err()
}

// generateMinimalConfig processes config.def.h and removes disabled patch blocks
func (pc *PatchConfig) generateMinimalConfig(configPath, outputPath string) error {
	inputFile, err := os.Open(configPath)
	if err != nil {
		return fmt.Errorf("cannot open %s: %w", configPath, err)
	}
	defer inputFile.Close()

	// Create output directory if it doesn't exist
	outputDir := filepath.Dir(outputPath)
	if outputDir != "." && outputDir != "" {
		if err := os.MkdirAll(outputDir, 0755); err != nil {
			return fmt.Errorf("cannot create directory %s: %w", outputDir, err)
		}
	}

	outputFile, err := os.Create(outputPath)
	if err != nil {
		return fmt.Errorf("cannot create %s: %w", outputPath, err)
	}
	defer outputFile.Close()

	writer := bufio.NewWriter(outputFile)
	defer writer.Flush()

	scanner := bufio.NewScanner(inputFile)

	// State tracking
	var conditionalStack []bool // true if we're in an enabled block
	var conditionalLines []int  // line numbers where conditionals start
	var patchStack []string     // track if each level is a patch-related condition
	lineNum := 0

	// Regex patterns for C preprocessor directives
	// Match #if with optional operators like !, &&, ||, etc.
	ifRegex := regexp.MustCompile(`^\s*#if\s+`)
	elifRegex := regexp.MustCompile(`^\s*#elif\s+`)
	elseRegex := regexp.MustCompile(`^\s*#else\b`)
	endifRegex := regexp.MustCompile(`^\s*#endif\b`)

	// Extract identifiers (handles !, &&, ||, ==, etc.)
	identifierRegex := regexp.MustCompile(`(\w+)`)

	// Helper function to extract the first identifier from a condition
	extractFirstIdentifier := func(condition string) string {
		matches := identifierRegex.FindStringSubmatch(condition)
		if len(matches) > 1 {
			return matches[1]
		}
		return ""
	}

	for scanner.Scan() {
		line := scanner.Text()
		lineNum++

		// Check for #if SOMETHING
		if ifRegex.MatchString(line) {
			// Extract the condition part (everything after #if)
			conditionStart := ifRegex.FindStringIndex(line)
			if conditionStart != nil {
				condition := line[conditionStart[1]:]
				identifier := extractFirstIdentifier(condition)

				// Check if this identifier is a known patch
				if _, isPatch := pc.AllPatches[identifier]; isPatch {
					// This is a patch condition - evaluate it
					isEnabled := pc.EnabledPatches[identifier]
					conditionalStack = append(conditionalStack, isEnabled)
					conditionalLines = append(conditionalLines, lineNum)
					patchStack = append(patchStack, identifier)

					// Output the #if line only if patch is enabled
					if isEnabled {
						writer.WriteString(line + "\n")
					}
				} else {
					// Not a patch condition, treat as normal code
					// Output it and track that we're now in a non-patch conditional
					writer.WriteString(line + "\n")
					conditionalStack = append(conditionalStack, true) // always output non-patch blocks
					conditionalLines = append(conditionalLines, lineNum)
					patchStack = append(patchStack, "") // empty string means "not a patch"
				}
			}
			continue
		}

		// Check for #elif SOMETHING
		if elifRegex.MatchString(line) {
			if len(conditionalStack) == 0 {
				return fmt.Errorf("line %d: #elif without matching #if", lineNum)
			}

			// Extract the condition part (everything after #elif)
			conditionStart := elifRegex.FindStringIndex(line)
			if conditionStart != nil {
				condition := line[conditionStart[1]:]
				identifier := extractFirstIdentifier(condition)
				currentLevel := len(conditionalStack) - 1

				// Check if this is a known patch and we're in a patch-related block
				if _, isPatch := pc.AllPatches[identifier]; isPatch && patchStack[currentLevel] != "" {
					// This is a patch, evaluate it
					isEnabled := pc.EnabledPatches[identifier]
					conditionalStack[currentLevel] = isEnabled
					patchStack[currentLevel] = identifier

					// Output #elif only if new condition is enabled
					if isEnabled {
						writer.WriteString(line + "\n")
					}
				} else {
					// Not a patch condition, always output it
					writer.WriteString(line + "\n")
					conditionalStack[currentLevel] = true
					patchStack[currentLevel] = ""
				}
			}
			continue
		}

		// Check for #else
		if elseRegex.MatchString(line) {
			if len(conditionalStack) == 0 {
				return fmt.Errorf("line %d: #else without matching #if", lineNum)
			}

			currentLevel := len(conditionalStack) - 1

			// Toggle only for patch-related blocks
			if patchStack[currentLevel] != "" {
				wasEnabled := conditionalStack[currentLevel]
				conditionalStack[currentLevel] = !wasEnabled

				// Output #else only if we're now in enabled code
				if conditionalStack[currentLevel] {
					writer.WriteString(line + "\n")
				}
			} else {
				// Non-patch block, always output it
				writer.WriteString(line + "\n")
			}
			continue
		}

		// Check for #endif
		if endifRegex.MatchString(line) {
			if len(conditionalStack) == 0 {
				return fmt.Errorf("line %d: #endif without matching #if", lineNum)
			}

			wasEnabled := conditionalStack[len(conditionalStack)-1]
			wasPatch := patchStack[len(patchStack)-1] != ""

			conditionalStack = conditionalStack[:len(conditionalStack)-1]
			conditionalLines = conditionalLines[:len(conditionalLines)-1]
			patchStack = patchStack[:len(patchStack)-1]

			// Output #endif only if the block was a patch block that was enabled
			if wasPatch && wasEnabled {
				writer.WriteString(line + "\n")
			} else if !wasPatch {
				// Non-patch blocks always output their #endif
				writer.WriteString(line + "\n")
			}
			continue
		}

		// For all other lines: output only if in enabled block (or not in any conditional)
		if len(conditionalStack) == 0 {
			// Not in any conditional block, always output
			writer.WriteString(line + "\n")
		} else if conditionalStack[len(conditionalStack)-1] {
			// In an enabled conditional block
			writer.WriteString(line + "\n")
		}
		// else: in a disabled block, skip the line
	}

	if len(conditionalStack) > 0 {
		return fmt.Errorf("unmatched #if at line %d", conditionalLines[len(conditionalLines)-1])
	}

	return scanner.Err()
}

// evaluatePatch evaluates whether a patch is enabled by resolving its value
// Handles simple values (0, 1, N/A) and complex expressions with || && !
func evaluatePatch(patchName string, rawValues map[string]string, cache map[string]bool) bool {
	// Check cache to avoid recomputation
	if cached, ok := cache[patchName]; ok {
		return cached
	}

	value, ok := rawValues[patchName]
	if !ok {
		cache[patchName] = false
		return false
	}

	value = strings.TrimSpace(value)

	// Check for simple values first
	if value == "0" || value == "N/A" {
		cache[patchName] = false
		return false
	}
	if value == "1" {
		cache[patchName] = true
		return true
	}

	// Complex expression - resolve identifiers and evaluate
	resolved := value
	identifierRegex := regexp.MustCompile(`\b([A-Z_]\w*)\b`)

	for {
		matches := identifierRegex.FindStringSubmatch(resolved)
		if len(matches) == 0 {
			break
		}

		identifier := matches[1]

		// If it's a known patch, recursively evaluate it
		if _, ok := rawValues[identifier]; ok && identifier != patchName {
			otherBool := evaluatePatch(identifier, rawValues, cache)
			replacement := "0"
			if otherBool {
				replacement = "1"
			}
			// Replace first occurrence
			resolved = strings.Replace(resolved, identifier, replacement, 1)
		} else {
			// Not a patch name, break to avoid infinite loop
			break
		}
	}

	// Evaluate the resolved expression
	result := evaluateExpression(resolved)
	cache[patchName] = result
	return result
}

// evaluateExpression evaluates a boolean expression with 0, 1, ||, &&, and !
// Respects proper operator precedence: ! > && > ||
func evaluateExpression(expr string) bool {
	return evaluateOr(strings.TrimSpace(expr))
}

// evaluateOr handles || operator (lowest precedence)
func evaluateOr(expr string) bool {
	parts := strings.Split(expr, "||")
	for _, part := range parts {
		if evaluateAnd(strings.TrimSpace(part)) {
			return true
		}
	}
	return false
}

// evaluateAnd handles && operator (medium precedence)
func evaluateAnd(expr string) bool {
	parts := strings.Split(expr, "&&")
	for _, part := range parts {
		if !evaluateNot(strings.TrimSpace(part)) {
			return false
		}
	}
	return true
}

// evaluateNot handles ! operator (highest precedence)
func evaluateNot(expr string) bool {
	expr = strings.TrimSpace(expr)
	if strings.HasPrefix(expr, "!") {
		return !evaluateNot(expr[1:])
	}
	// Base case: should be "0" or "1"
	return strings.TrimSpace(expr) == "1"
}
