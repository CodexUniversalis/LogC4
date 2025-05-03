/**
  * @file logc4.c
  * @author CodexUniversalis (codexuniversalisprime@gmail.com)
  * @brief The source file for the @a logc4.h header file.
  * @version 0.1.0
  * @date 2025-04-24: Created
  * Changelog:
  * - 2025-05-01: Worked on implementing functions from logc4.h.
  * @copyright Copyright (c) 2025
*/
#include <stdarg.h>
#include "logc4.h"

static bool std_char_type = false;

/*
This gets the current time string according to whether to use military
(24-hour) time or not.
*/
static char *getCurrentTime(){
    time_t now = time(NULL);
    struct tm *info = localtime(&now);
    if(milTime){
        char *time = calloc(timeLength24, sizeof(char));
        snprintf(time, timeLength24, "%02d:%02d:%02d", info->tm_hour,
                 info->tm_min, info->tm_sec);
        return time;
    }
    int hour = info->tm_hour;
    char *hrAdd = "AM";
    if(hour == 0){
        hour = 12;
    }
    else if(hour > 12){
        hour -= 12;
        hrAdd = "PM";
    }
    char *time = calloc(timeLength12, sizeof(char));
    snprintf(time, timeLength12, "%02d:%02d:%02d %s", hour, info->tm_min,
             info->tm_sec, (char *)hrAdd);
    return time;
}

/**
  * @brief Minimal function to check the internal allocation of memory without
  * the need for outside file and function names.
  *
  * @param ptr The returned pointer from the above alloc functions.
  * @param intFuncname The internal @a LogC4 function name that called the
  * memory allocation function.
  * @param allocFunc The alloc function that caused the error. Used in the log
  * message. Can be one of three values:
  *     - @a 1: @a malloc() failed.
  *     - @a 2: @a calloc() failed.
  *     - @a 3: @a realloc() failed.
  * @return true There were no memory allocation problems.
  * @return false There was a memory allocation problem.
*/
static bool internalCheckAlloc(void *ptr, char *intFuncName, int allocFunc){
    if(!ptr || errno == ENOMEM){
        char *alloc;
        switch(allocFunc){
            case 1:
                alloc = "m";
                break;
            case 2:
                alloc = "c";
                break;
            case 3:
                alloc = "re";
                break;
            default:
                alloc = "unknown_";
                break;
        }
        char *time = getCurrentTime();
        if(logCharType){
            fwprintf(logFileErr,
                     L"%s [ERROR]{logc4.c/%s} Memory allocation function "
                     L"'%salloc()' failed to allocate memory.\n", time,
                     intFuncName, alloc);
        }
        else{
            fprintf(logFileErr,
                    "%s [ERROR]{logc4.c/%s} Memory allocation function "
                    "'%salloc()' failed to allocate memory.\n", time,
                    intFuncName, alloc);
        }
        free(time);
        return false;
    }
    return true;
}

/**
  * @brief Checks if @a malloc(), @a calloc(), or @a realloc() failed.
  *
  * This function does not contain a call to @a internalLog() because
  * @a internalLog() calls this function.
  *
  * @param charType @a false if the given file name and function name are
  * normal string, @a true if they are wide character strings.
  * @param ptr The returned pointer from the above alloc functions.
  * @param funcName The name of the function that called this function. Used in
  * the log message.
  * @param intFuncname The internal @a LogC4 function name that called the
  * memory allocation function.
  * @param allocFunc The alloc function that caused the error. Used in the log
  * message. Can be one of three values:
  *     - @a 1: @a malloc() failed.
  *     - @a 2: @a calloc() failed.
  *     - @a 3: @a realloc() failed.
  *
  * @exitcode @a -1 if there is a memory error with @a malloc(), @a -2 if there
  * is a memory error with @a calloc(), and @a -3 if there is a memory error
  * with @a realloc().
*/
static void checkAlloc(bool charType, void *ptr, void *fileName,
                       void *funcName, char *intFuncName, int allocFunc){
    if(!ptr || errno == ENOMEM){
        char *alloc;
        switch(allocFunc){
            case 1:
                alloc = "m";
                break;
            case 2:
                alloc = "c";
                break;
            case 3:
                alloc = "re";
                break;
            default:
                alloc = "unknown_";
                break;
        }
        char *time = getCurrentTime();
        if(logCharType){
            if(fileName == NULL || funcName == NULL){
                fwprintf(logFileErr,
                         L"%s [ERROR]{logc4.c/%s} Memory allocation function "
                         L"'%salloc()' failed to allocate memory.\n", time,
                         intFuncName, alloc);
            }
            else{
                wchar_t *wFileName = (wchar_t *)fileName;
                wchar_t *wFuncName = (wchar_t *)funcName;
                if(!charType){
                    size_t length = strlen((char *)fileName);
                    wchar_t *wcs = calloc(length + 1, sizeof(wchar_t));
                    if(!internalCheckAlloc(wcs, "checkAlloc", 2)){
                        free(time);
                        return;
                    }
                    int wLength = swprintf(wcs, length, L"%s",
                                           (char *)fileName);
                    if(wLength < 0 || (size_t)wLength < length){
                        wchar_t *temp = realloc(wcs, (wLength + 1) *
                                                sizeof(wchar_t));
                        if(!internalCheckAlloc(temp, "checkAlloc", 3)){
                            free(time);
                            free(wcs);
                            return;
                        }
                        wcs = temp;
                    }
                    wFileName = wcs;

                    length = strlen((char *)fileName);
                    wcs = calloc(length + 1, sizeof(wchar_t));
                    if(!internalCheckAlloc(wcs, "checkAlloc", 2)){
                        free(time);
                        free(wFileName);
                        return;
                    }
                    wLength = swprintf(wcs, length, L"%s",
                                       (char *)fileName);
                    if(wLength < 0 || (size_t)wLength < length){
                        wchar_t *temp = realloc(wcs, (wLength + 1) *
                                                sizeof(wchar_t));
                        if(!internalCheckAlloc(temp, "checkAlloc", 3)){
                            free(time);
                            free(wcs);
                            free(wFileName);
                            return;
                        }
                        wcs = temp;
                    }
                    wFuncName = wcs;
                }
                fwprintf(logFileErr,
                         L"%s [ERROR](%ls/%ls){logc4.c/%s} Memory allocation "
                         L"function '%salloc()' failed to allocate memory.\n",
                         time, wFileName, wFuncName, intFuncName, alloc);
                if(!charType){
                    free(wFileName);
                    free(wFuncName);
                }
            }
        }
        else{
            if(fileName == NULL || funcName == NULL){
                fprintf(logFileErr,
                        "%s [ERROR]{logc4.c/%s} Memory allocation function "
                        "'%salloc()' failed to allocate memory.\n", time,
                        intFuncName, alloc);
            }
            else{
                char *nFileName = (char *)fileName;
                char *nFuncName = (char *)funcName;
                if(charType){
                    size_t wLength = wcslen((wchar_t *)fileName);
                    char *str = calloc(UTF8Bytes(wLength) + 1, sizeof(char));
                    if(!internalCheckAlloc(str, "checkAlloc", 2)){
                        free(time);
                        return;
                    }
                    int length = wcstombs(str, (wchar_t *)fileName, 2 *
                                          wLength);
                    if(length < 0 || (size_t)length < UTF8Bytes(wLength)){
                        char *temp = realloc(str, (length + 1) * sizeof(char));
                        if(!internalCheckAlloc(temp, "checkAlloc", 3)){
                            free(time);
                            free(str);
                            return;
                        }
                        str = temp;
                    }
                    nFileName = str;

                    wLength = wcslen((wchar_t *)fileName);
                    str = calloc(UTF8Bytes(wLength) + 1, sizeof(char));
                    if(!internalCheckAlloc(str, "checkAlloc", 2)){
                        free(time);
                        free(nFileName);
                        return;
                    }
                    length = wcstombs(str, (wchar_t *)fileName, 2 * wLength);
                    if(length < 0 || (size_t)length < UTF8Bytes(wLength)){
                        char *temp = realloc(str, (length + 1) * sizeof(char));
                        if(!internalCheckAlloc(temp, "checkAlloc", 3)){
                            free(time);
                            free(str);
                            free(nFileName);
                            return;
                        }
                        str = temp;
                    }
                    nFuncName = str;
                }
                fprintf(logFileErr,
                        "%s [ERROR](%s/%s){logc4.c/%s} Memory allocation"
                        "function '%salloc()' failed to allocate memory.\n",
                        time, nFileName, nFuncName, intFuncName, alloc);
                if(charType){
                    free(nFileName);
                    free(nFuncName);
                }
            }
        }
        free(time);
    }
}

/**
  * @brief Converts a normal string (char *) to a wide character string
  * (wchar_t *).
  *
  * @param str The normal string to convert.
  * @return wchar_t* The normal string as a wide character string.
*/
static wchar_t *stowcs(char *str){
    int length = (int)strlen(str);
    char *copy = calloc(length + 1, sizeof(char));
    checkAlloc(false, copy, NULL, NULL, "stowcs", 2);
    for(int i = 0; i < length; i++){
        signed char ch = str[i];
        if(ch < 0){
            copy[i] = (-ch) % 94 + 33;
        }
        else{
            copy[i] = ch;
        }
    }
    wchar_t *wcs = calloc(length + 1, sizeof(wchar_t));
    checkAlloc(false, wcs, NULL, NULL, "stowcs", 2);
    int wLength = swprintf(wcs, length + 1, L"%s", copy);
    if(wLength == -1){
        free(wcs);
        free(copy);
        char *time = getCurrentTime();
        if(logCharType){
            fwprintf(logFileErr,
                     L"%s [ERROR]{logc4.c/stowcs} The function swprintf() "
                     L"returned with a value of -1.\n", time);
        }
        else{
            fprintf(logFileErr,
                    "%s [ERROR]{logc4.c/stowcs} The function swprintf() "
                    "returned with a value of -1.\n", time);
        }
        free(time);
        wchar_t *null = calloc(5, sizeof(wchar_t));
        checkAlloc(false, null, NULL, NULL, "stowcs", 2);
        wcsncat(null, c_wNULL, c_NULL_LEN);
        return null;
    }
    else if(wLength < length){
        wchar_t *temp = realloc(wcs, (wLength + 1) * sizeof(wchar_t));
        checkAlloc(false, temp, NULL, NULL, "stowcs", 3);
        wcs = temp;
    }
    free(copy);
    return wcs;
}

/**
  * @brief Converts a wide character string (wchar_t *) to a normal string
  * (char *).
  *
  * @param wStr The wide character string to convert.
  * @return char* The wide character string as a normal string.
*/
static char *wcstos(wchar_t *wStr){
    size_t wLength = wcslen(wStr);
    char *str = calloc(UTF8Bytes(wLength) + 1, sizeof(char));
    checkAlloc(false, str, NULL, NULL, "wcstos", 2);
    size_t length = wcstombs(str, wStr, UTF8Bytes(wLength));
    if(length == (size_t)-1){
        free(str);
        char *time = getCurrentTime();
        if(logCharType){
            fwprintf(logFileErr,
                     L"%s [ERROR]{logc4.c/wcstos} The function wcstombs() "
                     L"returned with a value of -1. This means a wide "
                     L"character was encountered that could not be "
                     L"converted.\n", time);
        }
        else{
            fprintf(logFileErr,
                    "%s [ERROR]{logc4.c/wcstos} The function wcstombs() "
                    "returned with a value of -1. This means a wide character "
                    "was encountered that could not be converted.\n", time);
        }
        free(time);
        char *null = calloc(5, sizeof(char));
        checkAlloc(false, null, NULL, NULL, "wcstos", 2);
        strncat(null, c_NULL, c_NULL_LEN);
        return null;
    }
    else if(length < UTF8Bytes(wLength)){
        char *temp = realloc(str, (length + 1) * sizeof(char));
        checkAlloc(false, temp, NULL, NULL, "wcstos", 3);
        str = temp;
    }
    return str;
}

// Init stdout and stderr character type.
void logc4_stdInit(const bool charType){
    std_char_type = true;
}

// Log formatted message to stdout and stderr from the given charType format
// and function values .
int logc4_stdLog(const logc4_msg_t msgType, const bool charType,
                 const void *format, ...){
    FILE *outFile = msgType == LOGC4_ERROR ? stderr : stdout;
    int result = -1;
    va_list args;
    va_start(args, format);
    if(charType){
        result = vfwprintf(outFile, (wchar_t *)format, args);
    }
    else{
        result = vfprintf(outFile, (char *)format, args);
    }
    va_end(args);
    return result;
}
