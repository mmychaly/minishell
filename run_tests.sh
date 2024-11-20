#!/bin/bash

MINISHELL=./minishell # Path to the minishell executable
TEST_FILE=tests.txt   # Path to the test file

if [[ ! -f "$MINISHELL" ]]; then
    echo "Error: $MINISHELL not found!"
    exit 1
fi

if [[ ! -f "$TEST_FILE" ]]; then
    echo "Error: $TEST_FILE not found!"
    exit 1
fi

# Colors for output
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m" # No Color

# Counters
TESTS_RUN=0
TESTS_PASSED=0

# Read tests from the file
while IFS= read -r LINE; do
    # Skip empty lines and comments
    if [[ -z "$LINE" || "$LINE" == "#"* ]]; then
        continue
    fi

    # Parse the input and expected output
    if [[ "$LINE" == input:* ]]; then
        COMMAND="${LINE#input: }" # Extract the command after "input:"
    elif [[ "$LINE" == expected:* ]]; then
        EXPECTED_OUTPUT="${LINE#expected: }" # Extract the output after "expected:"

        # Run the command in minishell and capture the full output
        FULL_OUTPUT=$(echo "$COMMAND" | "$MINISHELL" 2>/dev/null)

        # Filter the actual output: remove lines with "minishell$"
        ACTUAL_OUTPUT=$(echo "$FULL_OUTPUT" | sed '/^minishell\$ /d' | sed '/^$/d' | tr -d '\r')

        # Increment the test counter
        TESTS_RUN=$((TESTS_RUN + 1))

        # Compare actual and expected output
        if [[ "$ACTUAL_OUTPUT" == "$EXPECTED_OUTPUT" ]]; then
            echo -e "${GREEN}Test $TESTS_RUN passed!${NC} Command: $COMMAND"
            TESTS_PASSED=$((TESTS_PASSED + 1))
        else
            echo -e "${RED}Test $TESTS_RUN failed!${NC} Command: $COMMAND"
            echo "Expected: $EXPECTED_OUTPUT"
            echo "Actual:   $ACTUAL_OUTPUT"
        fi
    fi
done < "$TEST_FILE"

# Final statistics
echo -e "\n$TESTS_RUN tests run. ${GREEN}$TESTS_PASSED passed.${NC} ${RED}$((TESTS_RUN - TESTS_PASSED)) failed.${NC}"
