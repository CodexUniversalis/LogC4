#!/bin/bash

# This removes all the files relating to the LogC4 library or the LogC4 man
# pages.
rem_logc4(){
    if [[ "$1" == "library" ]]; then
        printf "Removing the $COLOR_PURPLE_UNDERLINE\0logc4$COLOR_NORMAL library...\n"
        cd "$LIBDIR"
        printf "\t$COLOR_BRIGHT_YELLOW$LIBDIR/liblogc4.*$COLOR_NORMAL\n"
        sudo rm -f liblogc4.*
        cd pkgconfig
        printf "\t$COLOR_BRIGHT_YELLOW$PKGDIR/logc4.pc$COLOR_NORMAL\n"
        sudo rm -f logc4.pc
        cd ../../include
        printf "\t$COLOR_BRIGHT_YELLOW$HEADDIR/logc4.h$COLOR_NORMAL\n"
        sudo rm -f logc4.h
        printf "\t$COLOR_BRIGHT_YELLOW$HEADDIR/errnum.h$COLOR_NORMAL\n"
        sudo rm -f errnum.h
    elif [[ "$1" == "man_pages" ]]; then
        printf "Removing the $COLOR_PURPLE_UNDERLINE\0logc4$COLOR_NORMAL man pages...\n"
        cd $MANDIR
        for pages in "${manPages[@]}"; do
            pageCopies=($pages)
            printf "Deleting all copies of the $COLOR_PURPLE_UNDERLINE${pageCopies[0]}.3$COLOR_NORMAL man page...\n"
            for page in "${pageCopies[@]}"; do
                pagePath="$page.3.gz"
                pageRemovePath="$MANDIR/$page.3"
                if [[ -f "$pagePath" ]]; then
                    printf "$COLOR_BRIGHT_GREEN\t$pageRemovePath$COLOR_NORMAL - deleted\n"
                    sudo rm -f "$pagePath"
                else
                    printf "$COLOR_RED\t$pageRemovePath$COLOR_NORMAL - doesn't exist\n"
                fi
            done
        done
    else
        printf "The only passable arguments for remove are: 'library', 'man_pages', or no argument at all.\n"
        return 255
    fi
}

# Removes all LogC4 library files from the system.
remove_library_files(){
    calledDir=$(pwd)
    if [[ -z "$1" ]]; then
        printf "Removing the $COLOR_PURPLE_UNDERLINE\0logc4$COLOR_NORMAL library files...\n"
        rem_logc4 "library"
        rem_logc4 "man_pages"
    else
        rem_logc4 "$1"
    fi
    cd $calledDir
}

# If there is no argument passed then both the logc4 library and man pages are
# installed.
if [[ -z "$1" ]]; then
    remove_library_files

# If the first argument is equal to "library" then it only installs the logc4
# library.
elif [[ "${1,,}" == "library" ]]; then
    remove_library_files "${1,,,}"

# If the first argument is equal to "man_pages" then it only installs the logc4
# man pages.
elif [[ "${1,,}" == "man_pages" ]]; then
    remove_library_files "${1,,,}"

# If the script is not ran as intended, then it prints a message about its usage
# and exits with a value of (255).
else
    printf "This script only accepts 1 argument: \"library\", \"man_pages\", or no argument at all.\n"
    printf "\tUsage: ./remove.sh [library|man_pages]?\n"
    exit 255
fi
