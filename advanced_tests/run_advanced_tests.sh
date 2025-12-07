#!/bin/bash

# Advanced CUB3D Test Suite
# Tests parser validation and memory leaks with valgrind

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

EXEC="../cub3D"
TEST_DIR="./invalid_maps"
LOG_DIR="./logs"
PASS=0
FAIL=0
PARSER_PASS=0
PARSER_FAIL=0
LEAKS_PASS=0
LEAKS_FAIL=0

# Check if valgrind is installed
if ! command -v valgrind &> /dev/null; then
    echo -e "${YELLOW}Warning: valgrind not found. Leak tests will be skipped.${NC}"
    VALGRIND_AVAILABLE=0
else
    VALGRIND_AVAILABLE=1
fi

echo "========================================"
echo "   ADVANCED CUB3D PARSER & LEAK TESTS"
echo "========================================"
echo ""

# Change to script directory to ensure correct relative paths
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$SCRIPT_DIR"

# Create logs directory
rm -rf "$LOG_DIR"
mkdir -p "$LOG_DIR"

# Build the project
echo -e "${BLUE}Building project...${NC}"
make -C ../ > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi
echo -e "${GREEN}Build successful!${NC}"
echo ""

# Function to test parser
test_parser() {
    local file=$1
    local basename=$(basename "$file")
    
    output=$($EXEC "$file" 2>&1)
    exit_code=$?
    
    # All files in invalid_maps should be rejected (exit != 0)
    # And should contain "Error" in output
    if [ $exit_code -ne 0 ] && echo "$output" | grep -q "Error"; then
        echo -e "${GREEN}[OK]${NC} PARSER : $basename"
        ((PARSER_PASS++))
        return 0
    else
        echo -e "${RED}[FAIL]${NC} PARSER : $basename"
        if ! echo "$output" | grep -q "Error"; then
            echo -e "       ${YELLOW}⚠️  Error message doesn't include 'Error'${NC}"
        fi
        if [ $exit_code -eq 0 ]; then
            echo -e "       ${YELLOW}⚠️  Expected non-zero exit code, got 0${NC}"
        fi
        ((PARSER_FAIL++))
        return 1
    fi
}

# Function to test memory leaks
test_leaks() {
    local file=$1
    local basename=$(basename "$file")
    local logfile="$LOG_DIR/LOG_$basename"
    
    # Run valgrind
    valgrind --tool=memcheck \
             --leak-check=full \
             --leak-resolution=high \
             --show-reachable=no \
             --track-origins=yes \
             --log-file="$logfile" \
             $EXEC "$file" > /dev/null 2>&1
    
    # Check for definitely lost leaks (not just "still reachable")
    # If "definitely lost: 0 bytes" exists, no leaks
    # If the line doesn't exist at all but we see heap summary, also no leaks
    if grep -q "definitely lost: 0 bytes" "$logfile" || \
       (grep -q "HEAP SUMMARY" "$logfile" && ! grep -q "definitely lost: [1-9]" "$logfile"); then
        # No definitely lost leaks - OK
        echo -e "${GREEN}[OK]${NC} LEAKS  : $basename"
        rm -f "$logfile"
        ((LEAKS_PASS++))
        return 0
    else
        # Found definitely lost leaks
        echo -e "${RED}[FAIL]${NC} LEAKS  : $basename"
        ((LEAKS_FAIL++))
        return 1
    fi
}

# Function to run all tests on a file
test_file() {
    local file=$1
    local basename=$(basename "$file")
    
    echo "----------------------------------------"
    echo -e "${BLUE}Testing: $basename${NC}"
    
    # Test parser
    if test_parser "$file"; then
        # Only test leaks if parser test passed and valgrind is available
        if [ $VALGRIND_AVAILABLE -eq 1 ]; then
            test_leaks "$file"
        fi
    else
        echo -e "       LEAKS  : [skipped - parser failed]"
    fi
    echo ""
}

# Get test type from user
echo "Select test type:"
echo "1) Parser only"
echo "2) Leaks only"
echo "3) Both (Parser + Leaks)"
read -p "Enter choice [1-3] (default: 3): " choice
choice=${choice:-3}

case $choice in
    1) TEST_TYPE="parser";;
    2) TEST_TYPE="leaks";;
    3) TEST_TYPE="both";;
    *) TEST_TYPE="both";;
esac

echo ""
echo "========================================"
echo "Running tests..."
echo "========================================"
echo ""

# Count total files
total_files=$(find "$TEST_DIR" -name "*.cub" | wc -l)
current=0

# Test all invalid maps
for file in "$TEST_DIR"/*.cub; do
    if [ -f "$file" ]; then
        ((current++))
        echo -ne "\rProgress: $current/$total_files"
        
        basename=$(basename "$file")
        echo -e "\n${BLUE}Testing: $basename${NC}"
        
        # Run parser test
        if [ "$TEST_TYPE" = "parser" ] || [ "$TEST_TYPE" = "both" ]; then
            if test_parser "$file"; then
                parser_success=1
            else
                parser_success=0
            fi
        else
            parser_success=1  # Skip parser, assume success for leak test
        fi
        
        # Run leak test
        if [ "$TEST_TYPE" = "leaks" ] || [ "$TEST_TYPE" = "both" ]; then
            if [ $VALGRIND_AVAILABLE -eq 1 ] && [ $parser_success -eq 1 ]; then
                test_leaks "$file"
            elif [ $VALGRIND_AVAILABLE -eq 0 ]; then
                echo -e "       LEAKS  : [skipped - valgrind not available]"
            else
                echo -e "       LEAKS  : [skipped - parser failed]"
            fi
        fi
        echo ""
    fi
done

echo ""
echo "========================================"
echo "           TEST SUMMARY"
echo "========================================"
if [ "$TEST_TYPE" = "parser" ] || [ "$TEST_TYPE" = "both" ]; then
    echo -e "${BLUE}PARSER TESTS:${NC}"
    echo "  Passed: $PARSER_PASS"
    echo "  Failed: $PARSER_FAIL"
    echo "  Total:  $((PARSER_PASS + PARSER_FAIL))"
    echo ""
fi

if [ "$TEST_TYPE" = "leaks" ] || [ "$TEST_TYPE" = "both" ]; then
    if [ $VALGRIND_AVAILABLE -eq 1 ]; then
        echo -e "${BLUE}LEAK TESTS:${NC}"
        echo "  Passed: $LEAKS_PASS"
        echo "  Failed: $LEAKS_FAIL"
        echo "  Total:  $((LEAKS_PASS + LEAKS_FAIL))"
        echo ""
    fi
fi

TOTAL_PASS=$((PARSER_PASS + LEAKS_PASS))
TOTAL_FAIL=$((PARSER_FAIL + LEAKS_FAIL))

echo -e "${BLUE}OVERALL:${NC}"
echo "  Passed: $TOTAL_PASS"
echo "  Failed: $TOTAL_FAIL"
echo "  Total:  $((TOTAL_PASS + TOTAL_FAIL))"
echo "========================================"

# Exit with error if any test failed
if [ $TOTAL_FAIL -gt 0 ]; then
    echo -e "${RED}Some tests failed.${NC}"
    echo ""
    echo "Check log files in $LOG_DIR/ for details on memory leaks."
    exit 1
else
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
fi
