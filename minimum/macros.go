package main

import (
	"bufio"
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

// extractConfigMacros finds and extracts all CONFIG_* macros from patch/configs directory
func extractConfigMacros(configDir string) (map[string]string, error) {
	macros := make(map[string]string)

	// List all .h files in the configs directory
	entries, err := os.ReadDir(configDir)
	if err != nil {
		return nil, fmt.Errorf("cannot read config directory: %w", err)
	}

	for _, entry := range entries {
		if entry.IsDir() {
			continue
		}

		filename := entry.Name()
		if !strings.HasSuffix(filename, ".h") {
			continue
		}

		filepath := filepath.Join(configDir, filename)
		fileMacros, err := extractMacrosFromFile(filepath)
		if err != nil {
			return nil, fmt.Errorf("error processing %s: %w", filename, err)
		}

		// Add all macros from this file
		for name, content := range fileMacros {
			if _, exists := macros[name]; exists {
				// Macro already defined - this might be a problem
				// but we'll allow it (last definition wins)
			}
			macros[name] = content
		}
	}

	return macros, nil
}

// extractMacrosFromFile extracts CONFIG_* macros from a single file
func extractMacrosFromFile(filepath string) (map[string]string, error) {
	file, err := os.Open(filepath)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	macros := make(map[string]string)
	scanner := bufio.NewScanner(file)
	var currentMacro string
	var currentContent string
	var inMacro bool

	for scanner.Scan() {
		line := scanner.Text()

		// Check if this is the start of a CONFIG_* macro definition
		if strings.HasPrefix(strings.TrimSpace(line), "#define CONFIG_") {
			// Save previous macro if any
			if inMacro && currentMacro != "" {
				macros[currentMacro] = strings.TrimSpace(currentContent)
			}

			// Start new macro
			inMacro = true
			parts := strings.Fields(strings.TrimSpace(line))
			if len(parts) >= 2 {
				currentMacro = parts[1]
				// Content starts after the macro name
				content := strings.TrimSpace(line)
				content = strings.TrimPrefix(content, "#define")
				content = strings.TrimSpace(content)
				content = strings.TrimPrefix(content, currentMacro)
				content = strings.TrimSpace(content)
				// Remove trailing backslash if present (line continuation)
				content = strings.TrimSuffix(content, "\\")
				content = strings.TrimSpace(content)
				currentContent = content
			}
		} else if inMacro {
			// Continue building the macro content
			// Handle line continuation (backslash at end)
			trimmed := strings.TrimRight(line, " \t")

			if strings.HasSuffix(trimmed, "\\") {
				// Remove the backslash and continue on next line
				currentContent += "\n" + strings.TrimSuffix(trimmed, "\\")
			} else {
				// End of macro
				currentContent += "\n" + line
				// Only end if this line doesn't have a backslash (already handled above)
				if !strings.HasSuffix(trimmed, "\\") {
					macros[currentMacro] = strings.TrimSpace(currentContent)
					inMacro = false
					currentMacro = ""
					currentContent = ""
				}
			}
		}
	}

	// Don't forget the last macro if file ends without newline
	if inMacro && currentMacro != "" {
		macros[currentMacro] = strings.TrimSpace(currentContent)
	}

	if err := scanner.Err(); err != nil {
		return nil, err
	}

	return macros, nil
}
