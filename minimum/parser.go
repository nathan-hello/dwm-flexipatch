package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
)

// parsePatchesFile reads patches.h and evaluates all patch definitions
func parsePatchesFile(filepath string) (map[string]bool, error) {
	file, err := os.Open(filepath)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	patches := make(map[string]bool)
	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := scanner.Text()
		line = strings.TrimSpace(line)

		// Match: #define PATCH_NAME VALUE
		if strings.HasPrefix(line, "#define") {
			parts := strings.Fields(line)
			if len(parts) >= 3 {
				patchName := parts[1]
				value := strings.Join(parts[2:], " ")

				// Evaluate the value
				val, err := evaluateExpression(value, patches)
				if err != nil {
					return nil, fmt.Errorf("error evaluating %s: %v", patchName, err)
				}
				patches[patchName] = val
			}
		}
	}

	if err := scanner.Err(); err != nil {
		return nil, err
	}

	return patches, nil
}

// evaluateExpression evaluates a patch value expression
// Handles: simple 0/1, N/A, and boolean expressions with || and &&
func evaluateExpression(expr string, patches map[string]bool) (bool, error) {
	expr = strings.TrimSpace(expr)

	// Handle N/A - treat as false (disabled)
	if expr == "N/A" {
		return false, nil
	}

	// Handle simple 0/1 values
	if expr == "0" {
		return false, nil
	}
	if expr == "1" {
		return true, nil
	}

	// Handle boolean expressions with || and &&
	// Split by || first (lowest precedence)
	orParts := strings.Split(expr, "||")
	for _, orPart := range orParts {
		// For each OR part, evaluate AND expressions
		andResult := true
		andParts := strings.Split(orPart, "&&")
		for _, andPart := range andParts {
			andPart = strings.TrimSpace(andPart)
			// andPart should be a patch name or a literal
			val, err := evaluateLiteral(andPart, patches)
			if err != nil {
				return false, err
			}
			andResult = andResult && val
		}
		if andResult {
			return true, nil
		}
	}

	return false, nil
}

// evaluateLiteral evaluates a single literal (patch name or 0/1)
func evaluateLiteral(literal string, patches map[string]bool) (bool, error) {
	literal = strings.TrimSpace(literal)

	if literal == "0" {
		return false, nil
	}
	if literal == "1" {
		return true, nil
	}
	if literal == "N/A" {
		return false, nil
	}

	// Must be a patch name - look it up
	if val, exists := patches[literal]; exists {
		return val, nil
	}

	// Patch name not found yet - treat as 0 for forward references
	// This allows us to define patches in any order
	return false, nil
}

// validatePatchName checks if a string looks like a valid patch name
func validatePatchName(name string) bool {
	// Patch names should be uppercase with underscores
	re := regexp.MustCompile(`^[A-Z_][A-Z0-9_]*$`)
	return re.MatchString(name)
}
