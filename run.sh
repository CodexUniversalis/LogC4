#!/bin/bash

# Other scripts
INSTALL="scripts/install.sh"
REMOVE="scripts/remove.sh"
TEST="scripts/test.sh"

# Standard library substitutions
USRLOC="/usr/local"
MANDIR="$USRLOC/man/man3"
LIBDIR="$USRLOC/lib"
PKGDIR="$LIBDIR/pkgconfig"
HEADDIR="$USRLOC/include"

# Bash color literals.
COLOR_BRIGHT_GREEN="\e[1;32m"
COLOR_BRIGHT_CYAN="\e[1;36m"
COLOR_RED="\e[0;31m"
COLOR_BRIGHT_YELLOW="\e[1;33m"
COLOR_NORMAL="\e[0m"
COLOR_PURPLE_UNDERLINE="\e[1;4;35m"

# An associative array where the key is the man page in the man directory and
# the key is an array of man pages that are installed in the
# '/usr/local/man/man3' directory.
declare -r -A manPages=(
    ["errnum.3.man"]="errnum"
    ["logc4_init.3.man"]="
logc4_init
logc4_closeLogFiles
logc4_useWideChars
logc4_printInternMsgs
logc4_use24TimeFormat
"
    ["logc4_print.3.man"]="
logc4_print
logc4_wprint
logc4_printerr
logc4_wprinterr
"
    ["logc4_setLogFile.3.man"]="
logc4_setLogFile
logc4_setErrLogFile
logc4_getLogFilePath
logc4_getErrLogFilePath
"
)

# If the first argument is equal to "lib" then it only installs the logc4
# library.
if [[ "${1,,}" == "install" ]]; then
    source "$INSTALL" "$2"

# Removes all installed files for the library and man pages.
elif [[ "${1,,}" == "remove" ]]; then
    source "$REMOVE" "$2"

# If the first argument is equal to "test" then the executable for this library
# is run given the second argument. If the file is not passed then this returns
# a value of (255).
elif [[ "${1,,}" == "test" ]]; then
    if [[ -z "$2" ]]; then
        source "$TEST" ""
    else
        source "$TEST" "${@:2}"
    fi

# If the script is not ran as intended, then it prints a message about its usage
# and exits with a value of (255).
else
    printf "This script only accepts 1 argument: \"install\", \"remove\", \
\"test\", or no argument at all.\n"
    printf "\tUsage: ./run.sh [install|remove|test]?\n"
    exit 255
fi
