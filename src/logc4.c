/**
  * @file logc4.c
  * @author CodexUniversalis (codexuniversalisprime@gmail.com)
  * @brief The source file for the @a logc4.h header file.
  * @version 0.1.0
  * @date 2025-04-24: Created
  * Changelog:
  * - 2025-05-01: Worked on implementing functions from logc4.h.
  * - 2025-05-19: Fixed some functions that were broken.
  * @copyright Copyright (c) 2025
*/
#include <errno.h>
#include <stdarg.h>
#include <time.h>
#include "logc4.h"

/* The maximum length of a formatted time string. */
static const int TIME_STR_LEN = 28;
/* The time zone to use when getting the time. */
static int TIME_ZONE = 0;
/* A string literal of "NULL". */
static const char *c_NULL = "NULL";
/* A wide character string literal of L"NULL". */
static const wchar_t *c_wNULL = L"NULL";
/* The length of both the normal and wide character *NULL* string. */
static const int c_NULL_LEN = 4;

/**
  * @brief Gets the current time from the generated timespec object.
  *
  * @param timeStr A pointer to the string for the formatted time string.
  * @param len The length of @a timeStr.
  * @return Different values for different outcomes.
*/
static int getCurrentTimeFromTimeSpec(char *timeStr, int len){
    // TODO: Fix return statement in Doxygen comment.
    struct timespec ts = {0};
    int result = clock_gettime(0, &ts);
    if(result == -1){
        printf("getCurrentTimeFromTimespec() failed!\n");
        return -1;
    }
    struct tm tm = {0};

    // tzset();
    if(gmtime_r(&(ts.tv_sec), &tm) == NULL){
        return -2;
    }

    result = strftime(timeStr, len, "%F %T", &tm);
    if(result == 0){
        return -3;
    }
    len -= result - 1;

    result = snprintf(&timeStr[strlen(timeStr)], len, ".%03ld %s",
                      ts.tv_nsec / 1000000, tm.tm_zone);
    if(result >= len){
        return -4;
    }

    return 0;
}

/*
This gets the current time string according to whether to use the user local
time or UTC time.
*/
static char *getCurrentTime(){
    // TODO: Handle different timezones.
    // TODO: Handle outputs from getCurrentTimeFromTimeSpec()
    char *timeStr = calloc(TIME_STR_LEN, sizeof(char));
    int ret = getCurrentTimeFromTimeSpec(timeStr, TIME_STR_LEN);
    return timeStr;
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
static bool internalCheckAlloc(void *ptr, char *intFuncName, int lineNumber,
                               int allocFunc){
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
        fprintf(stderr,
                "%s [ERROR]{%s/%s:%d} Memory allocation function "
                "'%salloc()' failed to allocate memory.\n", time, __FILE__,
                intFuncName, lineNumber, alloc);
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
  * @param ptr The returned pointer from the above alloc functions.
  * @param intFuncname The internal @a LogC4 function name that called the
  * memory allocation function.
  * @param lineNumber The line number within this file that failed to allocate
  * the memory.
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
static void checkAlloc(void *ptr, char *intFuncName, int lineNumber,
                       int allocFunc, char *fileName, char *funcName){
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
        char *ref = NULL;
        if(fileName == NULL && funcName != NULL){
            ref = funcName;
        }
        else if(fileName != NULL && funcName == NULL){
            ref = fileName;
        }
        else if(fileName == NULL && funcName == NULL){
            fprintf(stderr,
                    "%s [ERROR]{%s/%s:%d} Memory allocation"
                    "function '%salloc()' failed to allocate memory.\n",
                    time, __FILE__, intFuncName, lineNumber, alloc);
        }
        if(ref == NULL){
            fprintf(stderr,
                    "%s [ERROR](%s/%s){%s/%s:%d} Memory allocation"
                    "function '%salloc()' failed to allocate memory.\n",
                    time, fileName, funcName, __FILE__, intFuncName,
                    lineNumber, alloc);
        }
        else{
            fprintf(stderr,
                    "%s [ERROR](%s){%s/%s:%d} Memory allocation"
                    "function '%salloc()' failed to allocate memory.\n",
                    time, ref, __FILE__, intFuncName, lineNumber, alloc);
        }
        free(time);
    }
}

/*
Converts a normal string (char *) to a wide character string (wchar_t *).
*/
wchar_t *logc4_stowcs(char *str){
    int length = (int)strlen(str);
    char *copy = calloc(length + 1, sizeof(char));
    checkAlloc(copy, __func__, __LINE__ - 1, 2, NULL, NULL);
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
    checkAlloc(wcs, __func__, __LINE__ - 1, 2, NULL, NULL);
    int wLength = swprintf(wcs, length + 1, L"%s", copy);
    int lineNum = __LINE__ - 1;
    if(wLength == -1){
        free(wcs);
        free(copy);
        char *time = getCurrentTime();
        fprintf(stderr,
                "%s [ERROR]{%s/%s:%d} The function swprintf() "
                "returned with a value of -1.\n", time, __FILE__, __func__,
                lineNum);
        free(time);
        wchar_t *null = calloc(5, sizeof(wchar_t));
        checkAlloc(null, __func__, __LINE__ - 1, 2, NULL, NULL);
        wcsncat(null, c_wNULL, c_NULL_LEN);
        return null;
    }
    else if(wLength < length){
        wchar_t *temp = realloc(wcs, (wLength + 1) * sizeof(wchar_t));
        checkAlloc(temp, __func__, __LINE__ - 1, 3, NULL, NULL);
        wcs = temp;
    }
    free(copy);
    return wcs;
}

/*
Converts a wide character string (wchar_t *) to a normal string (char *).
*/
char *logc4_wcstos(wchar_t *wStr){
    size_t wLength = wcslen(wStr);
    char *str = calloc(UTF8Bytes(wLength) + 1, sizeof(char));
    checkAlloc(str, __func__, __LINE__ - 1, 2, NULL, NULL);
    size_t length = wcstombs(str, wStr, UTF8Bytes(wLength));
    int lineNumber = __LINE__ - 1;
    if(length == (size_t)-1){
        free(str);
        char *time = getCurrentTime();
        fprintf(stderr,
                "%s [ERROR]{%s/%s:%d} The function wcstombs() "
                "returned with a value of -1. This means a wide character "
                "was encountered that could not be converted.\n", time,
                __FILE__, __func__, lineNumber);
        free(time);
        char *null = calloc(5, sizeof(char));
        checkAlloc(null, __func__, __LINE__ - 1, 2, NULL, NULL);
        strncat(null, c_NULL, c_NULL_LEN);
        return null;
    }
    else if(length < UTF8Bytes(wLength)){
        char *temp = realloc(str, (length + 1) * sizeof(char));
        checkAlloc(temp, __func__, __LINE__ - 1, 3, NULL, NULL);
        str = temp;
    }
    return str;
}

// Init stdout and stderr character type.
void logc4_stdInit(int timeZone){
    // TODO: Implement
}

// Log formatted message to stdout or stderr from the given format string
// and function values.
int logc4_stdLog(const logc4_msg_t msgType, const bool toStderr,
                 const void *format, ...){
    FILE *outFile = toStderr ? stderr : stdout;
    int result = -1;
    va_list args;
    va_start(args, format);
    result = vfprintf(outFile, (char *)format, args);
    va_end(args);
    return result;
}
