#!/bin/bash

# Characters
PASS="✓"
FAIL="X"

# Creats a file (and it's parent directories) or a given directory (and it's 
# parent directories) if it does not exist.
createNotExist(){
    if [[ "$1" == "file" ]]; then
        if [ ! -f "$2" ]; then
            mkdir -p "${2%/*}"
            touch "$2"
        fi
    elif [[ "$1" == "dir" ]]; then
        if [ ! -d "$2" ]; then
            mkdir -p "$2"
        fi
    fi
}

# Standard substitutions
STDOUT="out/prog_out/stdout.txt"
createNotExist "file" "$STDOUT"
STDERR="out/prog_out/stderr.txt"
createNotExist "file" "$STDERR"
STDALL="out/prog_out/stdall.txt"
createNotExist "file" "$STDALL"
CMPLOG="out/prog_out/cmp.log"
createNotExist "file" "$CMPLOG"
TEST="build/make/logc4_test"
if [ ! -f $TEST ]; then
    printf "There is no testing program.\n"
    exit 255
fi

# Helper variables for testing functions.
testDir="test_files"
createNotExist "dir" "$testDir"
testFilesDir="$testDir/tests"
createNotExist "dir" "$testFilesDir"
testResultsDir="$testDir/results"
createNotExist "dir" "$testResultsDir"
testResultsGenDir="$testResultsDir/generated"
createNotExist "dir" "$testResultsGenDir"
testResultsGivDir="$testResultsDir/given"
createNotExist "dir" "$testResultsGivDir"
totalTests=0
totalTestsPassed=0

# Tests the generated output with the given output file from the passed file.
test_output(){
    if [[ -z "$1" ]]; then
        printf "${COLOR_RED}[${FAIL}] FAILED  " \
               "${COLOR_NORMAL}No test_output file passed - %s\n" "$testFilePath"
    fi
    testGivFile="$testResultsGivDir/$1"
    if [ ! -f "$testGivFile" ]; then
        touch "$testGivFile"
    fi
    testGenFile="$testResultsGenDir/$1"
    if [ ! -d "$testGenFile" ]; then
        mkdir -p "$testResultsGenDir"
    fi
    cp "$STDALL" "$testGenFile"
    "$TEST" "cmp" "$CMPLOG" "$testGenFile" "$testGivFile"
    # cmp --silent "$testGenFile" "$testGivFile"
    exit_code=$?
    return $exit_code
}

# Runs the program with the given test file input and condenses the stdout and
# stderr outputs to a single file (STDALL). This then tests the generated output
# with the given test output.
test_file(){
    if [[ -z "$1" ]]; then
        printf "${COLOR_RED}[${FAIL}] FAILED  " \
               "${COLOR_NORMAL}No test_file file passed - %s\n" "$testFilePath"
    fi
    testFilePath="$testFilesDir/$1"
    testFile="$1"
    printf "${COLOR_BRIGHT_YELLOW}[ ] Testing ${COLOR_NORMAL}- %s\r" \
           "$testFilesDir/$testFile"
    "$TEST" "test" "$testFilePath" > "$STDOUT" 2> "$STDERR" || { 
        # If the previous command exits with non-zero (failure).
        printf "${COLOR_RED}[${FAIL}] FAILED  " \
               "${COLOR_NORMAL}Couldn't run program- %s\n" "$testFilePath"
        return "-1"
    }
    printf "err:\n" > "$STDALL"
    cat "$STDERR" >> "$STDALL"
    printf "\nout:\n" >> "$STDALL"
    cat "$STDOUT" >> "$STDALL"
    test_output "$testFile" && { # If the previous command exits with 0 (success).
        ((totalTestsPassed+=1))
        printf "${COLOR_BRIGHT_GREEN}[${PASS}] SUCCESS ${COLOR_NORMAL}- \
 %s\n" "$testFilePath"
    } || { # If the previous command exits with non-zero (failure).
        printf "${COLOR_RED}[${FAIL}] FAILED  ${COLOR_NORMAL}- %s\n" \
               "$testFilePath"
    }
    ((totalTests+=1))
    return 0
}

# Test the files with the program.
# If passed nothing, then this tests all the files int the ./test_files/tests
# directory
if [[ -z "$1" ]]; then
    for file in "$testFilesDir"/*; do
        if [[ -f "$file" ]]; then
            fileName="$(basename "$file")"
            test_file "$fileName"
        fi
    done
    if [[ $totalTestsPassed == $totalTests ]]; then
        printf "\n${COLOR_BRIGHT_GREEN}[${PASS}] "
    else
        printf "\n${COLOR_RED}[${FAIL}] "
    fi
    printf "${COLOR_BRIGHT_YELLOW}TOTAL TESTS PASSED: \
${COLOR_PURPLE_UNDERLINE}%d / %d${COLOR_NORMAL}\n" \
           "$totalTestsPassed" "$totalTests"
fi
