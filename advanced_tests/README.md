# Advanced CUB3D Tests

This directory contains advanced parser and memory leak tests for the cub3D project.

## Contents

- `invalid_maps/` - Collection of invalid .cub map files for testing parser error handling
- `textures/` - Texture files required by some test maps
- `logs/` - Valgrind output logs (created when tests are run)
- `run_advanced_tests.sh` - Main test script

## Test Categories

The invalid maps test the following scenarios:

1. **RGB Color Errors** (`invalid_RGB_*.cub`)
   - Missing RGB values
   - Invalid RGB format
   - RGB values out of range
   - Extra/missing commas

2. **Map Area Errors** (`invalid_map_area_*.cub`)
   - Unclosed maps
   - Invalid characters
   - Missing walls
   - Map connectivity issues

3. **Resolution Errors** (`invalid_res_*.cub`)
   - Invalid resolution format
   - Missing resolution values

4. **Texture Errors** (`invalid_tex_*.cub`)
   - Missing texture files
   - Invalid texture paths
   - Duplicate texture definitions
   - Wrong texture format

## Usage

Run the test script from the advanced_tests directory:

```bash
cd advanced_tests
./run_advanced_tests.sh
```

You'll be prompted to select test type:
1. **Parser only** - Tests if your parser correctly rejects invalid maps
2. **Leaks only** - Tests for memory leaks using valgrind (requires valgrind)
3. **Both** - Runs both parser and leak tests

## Requirements

- Your `cub3D` executable must be in the parent directory (`../cub3D`)
- For leak tests: `valgrind` must be installed

## Expected Behavior

All maps in `invalid_maps/` should:
- Be rejected by your parser (exit code != 0)
- Display an error message containing "Error"
- Not leak memory when run with valgrind

## Output

- ✅ Green `[OK]` - Test passed
- ❌ Red `[FAIL]` - Test failed
- Leak logs saved in `logs/` directory for failed tests

## Test Summary

At the end, you'll see:
- Parser test results (passed/failed)
- Leak test results (passed/failed)
- Overall statistics

## Note

These tests are based on the cub3D_leaks_maps_tester repository by mlaraki@42 Paris.
