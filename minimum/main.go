package main

import (
	"fmt"
	"os"
)

func main() {
	basePath := "/opt/dwm"

	// Phase 1: Parse patches.h
	fmt.Println("Phase 1: Parsing patches.h...")
	patches, err := parsePatchesFile(basePath + "/patches.h")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error parsing patches.h: %v\n", err)
		os.Exit(1)
	}
	fmt.Printf("  Found %d patches\n", len(patches))

	// Phase 2: Extract CONFIG_* macros
	fmt.Println("Phase 2: Extracting CONFIG_* macros...")
	macros, err := extractConfigMacros(basePath + "/patch/configs")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error extracting macros: %v\n", err)
		os.Exit(1)
	}
	fmt.Printf("  Found %d CONFIG_* macros\n", len(macros))

	// Phase 3: Process config.def.h
	fmt.Println("Phase 3: Processing config.def.h...")
	err = processConfigFile(basePath+"/config.def.h", patches, macros, basePath+"/config.minimal.h")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error processing config.def.h: %v\n", err)
		os.Exit(1)
	}

	fmt.Printf("Successfully generated: %s/config.minimal.h\n", basePath)
}
