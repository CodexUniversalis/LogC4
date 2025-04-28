#!/bin/bash

# Installs the logc4 library.
install_library(){
    printf "Installing $COLOR_PURPLE_UNDERLINE\0logc4$COLOR_NORMAL library...\n"
    if ! command -v cmake &> /dev/null ; then
        printf "$COLOR_BRIGHT_YELLOW\tcmake$COLOR_NORMAL not installed. Exiting with value$COLOR_RED 1.$COLOR_NORMAL\n"
        return 1;
    fi
    calledDir=$(pwd)
    buildDir="build/cmake"
    printf "Making $COLOR_BRIGHT_CYAN$buildDir$COLOR_NORMAL directory and changing to it...\n"
    mkdir -p $buildDir
    cd $buildDir
    printf "\tRunning $COLOR_BRIGHT_YELLOW[cmake ..]$COLOR_NORMAL...\n"
    cmake ../..
    printf "\tRunning $COLOR_BRIGHT_YELLOW[make all]$COLOR_NORMAL...\n"
    make all
    printf "\tRunning $COLOR_BRIGHT_YELLOW[make install]$COLOR_NORMAL...\n"
    sudo make install
    printf "\tRunning $COLOR_BRIGHT_YELLOW[sudo ldconfig]$COLOR_NORMAL...\n"
    sudo ldconfig
    cd $calledDir
}

# Installs the given man page from the first argument to all of the pages it
# represents in the manPages array.
install_man_page(){
    pageCopies=(${manPages["$1"]})
    printf "Copying and forcing the gzip of the $COLOR_PURPLE_UNDERLINE$1$COLOR_NORMAL file to the $COLOR_BRIGHT_YELLOW$MANDIR$COLOR_NORMAL directory...\n"
    for page in "${pageCopies[@]}"; do
        pageCopyPath="$MANDIR/$page.3"
        if [[ -f "$pageCopyPath.gz" ]]; then
            printf "$COLOR_BRIGHT_CYAN\t$pageCopyPath$COLOR_NORMAL - skipped, already installed\n"
        else
            printf "$COLOR_BRIGHT_GREEN\t$pageCopyPath$COLOR_NORMAL - install successful\n"
            sudo cp "$1" "$pageCopyPath"
            sudo gzip "$pageCopyPath"
        fi
    done
}

# Installs the logc4 man pages.
install_man_pages(){
    printf "Installing $COLOR_PURPLE_UNDERLINE\0logc4$COLOR_NORMAL man pages...\n"
    calledDir=$(pwd)
    sudo mkdir -p "$MANDIR"
    cd man
    for file in *; do
        if [[ -f "$file" ]]; then
            install_man_page "$file"
        fi
    done
    cd $currentDir
}

# If there is no argument passed then both the logc4 library and man pages are
# installed.
if [[ -z "$1" ]]; then
    install_library
    install_man_pages

# If the first argument is equal to "library" then it only installs the logc4
# library.
elif [[ "${1,,}" == "library" ]]; then
    install_library

# If the first argument is equal to "man_pages" then it only installs the logc4
# man pages.
elif [[ "${1,,}" == "man_pages" ]]; then
    install_man_pages

# If the script is not ran as intended, then it prints a message about its usage
# and exits with a value of (255).
else
    printf "This script only accepts 1 argument: \"library\", \"man_pages\", or no argument at all.\n"
    printf "\tUsage: ./install.sh [library|man_pages]?\n"
    exit 255
fi
