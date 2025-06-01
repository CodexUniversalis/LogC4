/**
  * @file test.c
  * @author CodexUniversalis (codexuniversalisprime@gmail.com)
  * @brief The entry point for testing the @a LogC4 library.
  * @version 0.1.0
  * @date 2025-04-24: Created. @n @n
  * - 2025-05-21: Light refactoring.
  * GitHub <a href="@ghc/11330ccad45e238314dca87fddfa75bc60ef920d">commit</a>.
  * - 2025-05-22: Refactoring references to old LogC4 functions to the updated
  * version.
  * GitHub <a href="@ghc/fa4effda02e18f016e3d597ae695543f35789e56">commit</a>.
  * - 2025-05-26: Changed all old @a LogC4 functions to the new functions.
  * GitHub <a href="@ghc/8c747b6b07242a5cb8baaaba6b414a38047fe5e6">commit</a>.
  * @copyright Copyright (c) 2025
*/
#include "logc4.h"
#include <errno.h>
#include <linux/limits.h>
#include <locale.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

// TODO: Refactor to use new LogC4 functions and rewrite the tests.

/**
  * @brief A wide character string.
*/
// TODO: Determine if to change this to String struct containing a wide
// character and a normal character string
typedef struct{
    /**
      * @brief The wide character string.
    */
    wchar_t *str;
    /**
      * @brief The length of the wide character string.
    */
    size_t len;
} WStr;

/* The test file stream pointer. */
static FILE *testFilePtr = NULL;
/* The standard log output file. */
static FILE *logOut = NULL;
/* The absolute path of the standard log output file. */
static char *logOutPath = NULL;
/* The error log output file. */
static FILE *logErr = NULL;
/* The absolute path of the error log output file. */
static char *logErrPath = NULL;
/* The max length (100) of the test file line. */
static size_t LINE_LENGTH = 100;
/* Whether a test file was given or not. */
static bool hasTestFile = false;
/* The absolute file path to the given test file. */
static char *fullFilePath = NULL;
/* The function aliases in the test file. */
static WStr testFuncts[] = {
    {L"stowcs", 6},
    {L"wcstos", 6},
    {L"stdInit", 7},
    {L"stdLog", 6},
    {L"fileOpen", 8},
    {L"fileClose", 9},
    {L"fileLog", 7},
    {0}
};

/**
  * @brief Frees all of the allocated memory of the given @a WStr and sets
  * all of the properties to default values.
  *
  * @param wStr The @a WStr to free.
*/
static void freeWStr(WStr wStr){
    free(wStr.str);
    wStr.str = NULL;
    wStr.len = 0;
}

/*
Gets the current line for the test file.
*/
static WStr getLine(FILE *filePtr){
    WStr line = {0};
    wchar_t *temp = calloc(LINE_LENGTH, sizeof(wchar_t));
    line.str = fgetws(temp, LINE_LENGTH, filePtr);
    if(line.str != NULL){
        line.len = wcslen(line.str) - 1;
        line.str[line.len] = L'\0';
        temp = realloc(line.str, (line.len + 1) * sizeof(wchar_t));
        line.str = temp;
    }
    else{
        free(temp);
    }
    return line;
}

/*
Opens the test file.
*/
static void openTestFile(char *filePath){
    if(!hasTestFile){
        size_t fpLen = strlen(filePath);
        testFilePtr = fopen(filePath, "r");
        fullFilePath = realpath(filePath, NULL);
        size_t ffpLen = strlen(fullFilePath);
        if(fullFilePath == NULL){
            fullFilePath = calloc(fpLen + 1, sizeof(char));
            strncat(fullFilePath, filePath, fpLen);
        }
        else{
            char *temp = realloc(fullFilePath, ffpLen + 1);
            fullFilePath = temp;
        }
        if(!testFilePtr){
            fprintf(stderr, "{test.c} Error: Cannnot open test file: %s\n",
                    fullFilePath);
            return;
        }
        hasTestFile = true;
    }
    else{
        fprintf(stderr, "{test.c} Error: Already opened test file: %s\n",
                fullFilePath);
    }
}

/*
This gets the function that is present in the given string.
*/
static WStr getFunc(WStr str){
    int i = 0;
    WStr func = {0};
    while((func = testFuncts[i++]).len != 0){
        if(wcscmp(str.str, func.str) == 0){
            break;
        }
    }
    return func;
}

/*
Reads and interprets the test file line by line.
*/
static void runTestFile(){
    if(!hasTestFile){
        return;
    }
    WStr line;
    while((line = getLine(testFilePtr)).len != 0){
        WStr func = getFunc(line);
        if(func.len != 0){
            if(wcscmp(func.str, L"stowcs") == 0){
                // TODO: Implement.
            }
            else if(wcscmp(func.str, L"wcstos") == 0){
                // TODO: Implement.
            }
            else if(wcscmp(func.str, L"stdInit") == 0){
                // TODO: Implement.
            }
            else if(wcscmp(func.str, L"stdLog") == 0){
                // TODO: Implement.
            }
            else if(wcscmp(func.str, L"fileOpen") == 0){
                // TODO: Implement.
            }
            else if(wcscmp(func.str, L"fileClose") == 0){
                // TODO: Implement.
            }
            else if(wcscmp(func.str, L"fileLog") == 0){
                // TODO: Implement.
            }
            freeWStr(line);
        }
    }
}

/*
Closes the test file stream and frees all memory allocated during test file
testing.
*/
static void closeTestFile(){
    if(hasTestFile){
        fclose(testFilePtr);
        testFilePtr = NULL;
        hasTestFile = false;
    }
    if(fullFilePath != NULL){
        free(fullFilePath);
        fullFilePath = NULL;
    }
}

/**
  * @brief Completely test the given test file.
  *
  * @param filePath The absolute/relative path of the test file.
*/
static void testFile(char *filePath){
    openTestFile(filePath);
    runTestFile();
    closeTestFile();
}

/**
  * @brief Get the next @a wint_t character from the given string at the given
  * position + 1.
  *
  * @param ch A pointer to a @a wint_t variable.
  * @param string The @a WStr struct to get the character from.
  * @param pos The current position within the string.
  * @return bool @a false if there is no next character, @a true otherwise.
*/
static bool getNextChar(wint_t *ch, WStr string, size_t *pos){
    if(*pos >= string.len){
        logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                     "Trying to access a character outside of the string's "
                     "bounds.");
        return false;
    }
    *ch = string.str[++(*pos)];
    return true;
}

/**
  * @brief Checks the given @a WStr from the given position if it matches any
  * of the special escape characters.
  *
  * @param code The special escape code.
  * @param string The @a WStr to check.
  * @param pos The position of the first character check.
  * @return int @a 1 if the check failed during escape code of @a '!', @a 2 if
  * the check failed during escape code of @a '@', @a 0 otherwise.
*/
static int checkEsc(wint_t code, WStr string, size_t *pos){
    wint_t prevChar = 0;
    wint_t currChar = 0;
    if(code == L'!'){
        currChar = string.str[*pos];
        if(currChar != L'0' && currChar != L'1'){
            return 1;
        }
        prevChar = currChar;
        if(!getNextChar(&currChar, string, pos)){
            return 1;
        }
        switch(prevChar){
            case L'0':
                if(currChar <= L'0' || currChar > L'9'){
                    return 1;
                }
                break;
            case L'1':
                if(currChar < L'0' || currChar > L'2'){
                    return 1;
                }
                break;
            default:
                return 1;
        }
        for(int i = 0; i < 6; i++){
            prevChar = currChar;
            if(!getNextChar(&currChar, string, pos)){
                return 1;
            }
            switch(i % 3){
                case 0:
                    if(currChar != L':'){
                        return 1;
                    }
                    break;
                case 1:
                    if(currChar < L'0' || currChar > L'5'){
                        return 1;
                    }
                    break;
                case 2:
                    if(currChar < L'0' || currChar > L'9'){
                        return 1;
                    }
                    break;
                default:
                    return 1;
            }
        }
        prevChar = currChar;
        if(!getNextChar(&currChar, string, pos)){
            return 1;
        }
        if(currChar != L' '){
            return 1;
        }
        prevChar = currChar;
        if(!getNextChar(&currChar, string, pos)){
            return 1;
        }
        if(currChar != L'A' && currChar != L'P'){
            return 1;
        }
        prevChar = currChar;
        if(!getNextChar(&currChar, string, pos)){
            return 1;
        }
        if(currChar != L'M'){
            return 1;
        }
    }
    else if(code == L'@'){
        currChar = string.str[*pos];
        if(currChar < L'0' || currChar > L'2'){
            return 2;
        }
        prevChar = currChar;
        if(!getNextChar(&currChar, string, pos)){
            return 2;
        }
        switch(prevChar){
            case L'0':
            case L'1':
                if(currChar < L'0' || currChar > L'9'){
                    return 2;
                }
                break;
            case L'2':
                if(currChar < L'0' || currChar > L'3'){
                    return 2;
                }
                break;
            default:
                return 2;
        }
        for(int i = 0; i < 6; i++){
            prevChar = currChar;
            if(!getNextChar(&currChar, string, pos)){
                return 2;
            }
            switch(i % 3){
                case 0:
                    if(currChar != L':'){
                        return 2;
                    }
                    break;
                case 1:
                    if(currChar < L'0' || currChar > L'5'){
                        return 2;
                    }
                    break;
                case 2:
                    if(currChar < L'0' || currChar > L'9'){
                        return 2;
                    }
                    break;
                default:
                    return 2;
            }
        }
    }
    return 0;
}

/* The wide character that denotes an escapable character may follow. */
static wint_t spcEscCh = L'\\';
/* An array of the special escape characters that can make up the test files
being compared. */
static WStr spcEsc = {L"!@", 2};

/*
Compares the given two files by either wide characters or normal characters.
*/
static int cmpFiles(const char *file1, const char *file2, const int wideChars){
    FILE *file1_fd = fopen(file1, "r");
    if(file1_fd == NULL){
        logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                     "Cannot open the first file: %s.",
                     file1);
        return 1;
    }
    FILE *file2_fd = fopen(file2, "r");
    if(file2_fd == NULL){
        logc4_stdLog(false, LOGC4_ERROR, __FILE__, __func__,
                     "Cannot open the second file: %s.",
                     file2);
        fclose(file1_fd);
        return 2;
    }
    int numChars = 250;
    wchar_t *line1 = calloc(numChars, sizeof(wchar_t));
    wchar_t *l1Ret = NULL;
    wchar_t *line2 = calloc(numChars, sizeof(wchar_t));
    wchar_t *l2Ret = NULL;
    while((l1Ret = fgetws(line1, numChars, file1_fd)) != NULL &&
          (l2Ret = fgetws(line2, numChars, file2_fd)) != NULL){
        size_t l1Len = wcslen(line1);
        size_t l1Pos = 0;
        size_t l2Len = wcslen(line2);
        size_t l2Pos = 0;
        wint_t ch1 = 0;
        wint_t ch2 = 0;
        int escIndex = -1;
        while(l1Pos < l1Len && l2Pos < l2Len){
            ch1 = line1[l1Pos];
            ch2 = line2[l2Pos];
            if(!wideChars){
                if(ch1 > 127){
                    logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                                 "The first file (%s) contains a non-ASCII "
                                 "character.",
                                 file1);
                    fclose(file1_fd);
                    fclose(file2_fd);
                    free(line1);
                    free(line2);
                    return 3;
                }
                else if(ch2 > 127){
                    logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                                 "The second file (%s) contains a non-ASCII "
                                 "character.",
                                 file1);
                    fclose(file1_fd);
                    fclose(file2_fd);
                    free(line1);
                    free(line2);
                    return 4;
                }
                else if(ch1 != ch2){
                    logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                                 "The first file (%s) and the second "
                                 "file (%s) do not match ASCII characters.",
                                 file1, file2);
                    fclose(file1_fd);
                    fclose(file2_fd);
                    free(line1);
                    free(line2);
                    return 5;
                }
                l1Pos++;
                l2Pos++;
                continue;
            }
            if(ch1 == spcEscCh){
                if(l1Pos < l1Len - 1){
                    wint_t temp = line1[l1Pos + 1];
                    for(size_t i = 0; i < spcEsc.len; i++){
                        if(temp == (wint_t)spcEsc.str[i]){
                            escIndex = i;
                            break;
                        }
                    }
                }
                if(escIndex != -1){
                    int retVal = checkEsc(spcEsc.str[escIndex], (WStr){
                        line2, l2Len
                    }, &l2Pos);
                    switch(retVal){
                        case 1:
                            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                                         "The second file (%s) does not match "
                                         "the first file (%s) because of a "
                                         "12-hour time format.",
                                         file2, file1);
                            fclose(file1_fd);
                            fclose(file2_fd);
                            free(line1);
                            free(line2);
                            return 6;
                        case 2:
                            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                                         "The second file (%s) does not match "
                                         "the first file (%s) because of a "
                                         "24-hour time format.",
                                         file2, file1);
                            fclose(file1_fd);
                            fclose(file2_fd);
                            free(line1);
                            free(line2);
                            return 7;
                        default:
                            l1Pos += 2;
                            l2Pos += 1;
                            break;
                    }
                    escIndex = -1;
                    continue;
                }
            }
            if(ch2 == spcEscCh){
                if(l2Pos < l2Len - 1){
                    wint_t temp = line2[l2Pos + 1];
                    for(size_t i = 0; i < spcEsc.len; i++){
                        if(temp == (wint_t)spcEsc.str[i]){
                            escIndex = i;
                            break;
                        }
                    }
                }
                if(escIndex != -1){
                    int retVal = checkEsc(spcEsc.str[escIndex], (WStr){
                        line1, l1Len
                    }, &l1Pos);
                    switch(retVal){
                        case 1:
                            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                                         "The first file (%s) does not match "
                                         "the second file (%s) because of a "
                                         "12-hour time format.",
                                         file1, file2);
                            fclose(file1_fd);
                            fclose(file2_fd);
                            free(line1);
                            free(line2);
                            return 8;
                        case 2:
                            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                                         "The first file (%s) does not match "
                                         "the second file (%s) because of a "
                                         "24-hour time format.",
                                         file1, file2);
                            fclose(file1_fd);
                            fclose(file2_fd);
                            free(line1);
                            free(line2);
                            return 9;
                        default:
                            l2Pos += 2;
                            l1Pos += 1;
                            break;
                    }
                    escIndex = -1;
                    continue;
                }
            }
            if(ch1 != ch2){
                logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                             "The first file (%s) and the second file (%s) do "
                             "not match wide characters.",
                             file1, file2);
                fclose(file1_fd);
                fclose(file2_fd);
                free(line1);
                free(line2);
                return 10;
            }
            l1Pos++;
            l2Pos++;
        }
        if(l1Pos == l1Len && l2Pos != l2Len){
            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                         "The second file (%s) does not match the first file "
                         "(%s) because a line in the second file is longer.",
                         file2, file1);
            fclose(file1_fd);
            fclose(file2_fd);
            free(line1);
            free(line2);
            return 11;
        }
        else if(l1Pos != l1Len && l2Pos == l2Len){
            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                         "The first file (%s) does not match the second file "
                         "(%s) because a line in the first file is longer.",
                         file1, file2);
            fclose(file1_fd);
            fclose(file2_fd);
            free(line1);
            free(line2);
            return 12;
        }
    }
    if(l1Ret != NULL && l2Ret == NULL){
        l1Ret = fgetws(line1, numChars, file1_fd);
        if(l1Ret != NULL){
            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                         "The first file (%s) is longer than the second file "
                         "(%s).",
                         file1, file2);
            fclose(file1_fd);
            fclose(file2_fd);
            free(line1);
            free(line2);
            return 13;
        }
    }
    else if(l1Ret == NULL && l2Ret != NULL){
        l2Ret = fgetws(line2, numChars, file2_fd);
        if(l2Ret != NULL){
            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                         "The second file (%s) is longer than the first file "
                         "(%s).",
                         file2, file1);
            fclose(file1_fd);
            fclose(file2_fd);
            free(line1);
            free(line2);
            return 14;
        }
    }
    fclose(file1_fd);
    fclose(file2_fd);
    free(line1);
    free(line2);
    return 0;
}

/**
  * @brief The main entry point of the program.
  *
  * @param argc The number of arguments passed to the program.
  * @param argv The arguments passed to the program.
  * @return int The exit code of the program.
*/
int main(int argc, char **argv){
    if(argc <= 1){
        logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                     "Usage{test.c}: logc4_test (cmp | test) [FILE...].");
        return 2;
    }
    // Must be set to handle UTF-8 characters.
    setlocale(LC_ALL, "en_US.UTF-8");
    if(strcmp("cmp", argv[1]) == 0){
        // TODO: Refactor and implement.
        // logc4_init(1, 1, 1);
        if(argc <= 4){
            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                         "The /cmp/ subcommand requires three (3) file paths. "
                         "The first is the log output and the last two are "
                         "the files to compare.");
            return 3;
        }
        // logc4_setLogFile(argv[2], 0);
        // logc4_setErrLogFile(argv[2], 0);
        int retVal = cmpFiles(argv[3], argv[4], true);
        // logc4_closeLogFiles();
        return retVal == 0 ? 0 : retVal + 4;
    }
    else if(strcmp("test", argv[1]) == 0){
        if(argc == 2){
            logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                         "No file(s) passed to the /test/ subcommand.");
            return 4;
        }
        // Assume all arguments after the second one to be test files.
        for(int i = 2; i < argc; i++){
            testFile(argv[i]);
        }
        return 0;
    }
    logc4_stdLog(LOGC4_ERROR, true, __FILE__, __func__,
                 "Unknown subcommand /%s/.",
                 argv[1]);
    return 1;
}
