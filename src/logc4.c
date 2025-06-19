/**
  * @file logc4.c
  * @author CodexUniversalis (codexuniversalisprime@gmail.com)
  * @brief The source file for the @a logc4.h header file.
  *
  * For proper handling of @a UTF-8 characters, ensure that
  * <i>setlocale(LC_ALL, "en_US,UTF-8")</i> is called before using this
  * library.
  *
  * @version 0.1.0
  * @date 2025-04-24: Created. @n @n
  * Changelog:
  * - 2025-05-01: Worked on implementing functions from logc4.h.
  * GitHub <a href="@ghc/038b3387d1b05ff13556ba55e1489a5ac00d3af6">commit</a>.
  * - 2025-05-03: Implemented mostly old code.
  * GitHub <a href="@ghc/a2efdfb47228bbfdde5f36d7bd668304dfdc19b9">commit</a>.
  * - 2025-05-19: Fixed some functions that were broken.
  * GitHub <a href="@ghc/78f4278d8c60d382af35c1e65b7597f3d487d286">commit</a>.
  * - 2025-05-20: Refactor. Implemented logc4_stdLog().
  * GitHub <a href="@ghc/ea353fd037a713db521b873883e769dd967106a1">commit</a>.
  * - 2025-05-21: Refactor. Implemented logc4_fileLog().
  * GitHub <a href="@ghc/1178c2d3db540b7e074684eae82cd47ca3e602a7">commit</a>.
  * - 2025-05-26: Worked on implementing timezones.
  * GitHub <a href="@ghc/8c747b6b07242a5cb8baaaba6b414a38047fe5e6">commit</a>.
  * - 2025-05-31: Made sure GitHub was spelled correctly.
  * GitHub <a href="@ghc/e541157c808a9a20a7b611e696840db7d67d443e">commit</a>.
  * - 2025-06-08: Added the timezone enum from @a timezones.h and refactored
  * the layout for the timezone info. Also renamed some instances of
  * @a timeZone to @a timezone and moved @a TZInfo to @a timezones.h.
  * GitHub <a href="@ghc/0c3f0c205507cf393e7a22e89a5bf8fd1aa9afe7">commit</a>.
  * - 2025-06-15: The only timezones are @a LOGC4_TZ_LOCAL and @a LOGC4_TZ_UTC.
  * Also added the ability to convert from communist (24-hour) to
  * proper (12-hour) format.
  * GitHub <a href="@ghc/cb907a7e6fd9236ef1244a7818c49f0a2b8126b7">commit</a>.
  * - 2025-06-15: Removed mention of other timezones.
  * GitHub <a href="@ghc/5f6d5bf8a59c241a1a851f8adc1d6919ef934bcb">commit</a>.
  * - 2025-06-15: Updated comments for files.
  * GitHub <a href="@ghc/525644530ddb5cba5235f930ecbfd615283f1296">commit</a>.
  * - 2025-06-16: Removed the logc4_stowcs() and logc4_wcstos() functions.
  * Github <a href="@ghc/28e89b59e944fecf5a74264726772faf85e29143">commit</a>.
  * @copyright Copyright (c) 2025
*/
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "logc4.h"

// TODO: MAKE THREAD SAFE.

/* The maximum length of a formatted time string. */
#define TIME_STR_LEN 40
/* A string literal of "NULL". */
#define c_NULL "NULL"
/* The length of both the normal and wide character *NULL* string. */
#define c_NULL_LEN 4

/* The logc4_file_t for logging to stdout or stderr. */
static logc4_file_t STDLOG = {
    .file = NULL,
    .filePath = NULL,
    .timezone = LOGC4_TZ_LOCAL,
    .display = {
        .date = true,
        .properTimeFormat = false,
        .timezone = true
    }
};

/**
  * @brief Checks if @a malloc(), @a calloc(), or @a realloc() failed.
  *
  * This function is used only when checking allocations for getting the time
  * formatted string
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
*/
static void timeCheckAlloc(const void *ptr, const char *intFuncName,
                           const int lineNumber, const int allocFunc,
                           const char *fileName, const char *funcName){
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
        int ref = 0;
        if(fileName == NULL && funcName != NULL){
            ref = 2;
        }
        else if(fileName != NULL && funcName == NULL){
            ref = 1;
        }
        if(fileName == NULL && funcName == NULL){
            fprintf(stderr,
                    "UNKNOWN [ERROR]{%s/%s:%d} Memory allocation "
                    "function '%salloc()' failed to allocate memory while "
                    "getting the formatted time string.\n",
                    __FILE__, intFuncName, lineNumber, alloc);
        }
        else if(ref == 0){
            fprintf(stderr,
                    "UNKNOWN [ERROR](%s/%s){%s/%s:%d} Memory allocation "
                    "function '%salloc()' failed to allocate memory while "
                    "getting the formatted time string.\n",
                    fileName, funcName, __FILE__, intFuncName, lineNumber,
                    alloc);
        }
        else{
            fprintf(stderr,
                    "UNKNOWN [ERROR](%s){%s/%s:%d} Memory allocation "
                    "function '%salloc()' failed to allocate memory while "
                    "getting the formatted time string.\n",
                    ref == 1 ? fileName : funcName, __FILE__,
                    intFuncName, lineNumber, alloc);
        }
    }
}

/**
  * @brief Gets the current time from the generated timespec object.
  *
  * @param timeStr A pointer to the string for the formatted time string.
  * @param len The length of @a timeStr.
  * @param tzEnum The timezone enum to use.
  * @param display The @a logc4_display_t struct that is used to determine
  * what information to display.
  * @return int If the value is not @a 0, then an error occurred and the
  * contents of @a timeStr are undefined.
*/
static int getCurrentTimeFromTimeSpec(char *timeStr, int len,
                                      logc4_tz_t tzEnum,
                                      logc4_display_t display){
    struct timespec ts = {0};
    int result = clock_gettime(0, &ts);
    if(result == -1){
        return -1;
    }

    char *UTCStr = "UTC";
    char *proper = "";
    extern char *tzname[2];
    extern long timezone;
    extern int daylight;
    struct tm tm = {0};
    if(tzEnum == LOGC4_TZ_LOCAL){
        tzset();
        if(localtime_r(&(ts.tv_sec), &tm) == NULL){
            return -2;
        }
    }
    else if(tzEnum == LOGC4_TZ_UTC){
        if(gmtime_r(&(ts.tv_sec), &tm) == NULL){
            return -3;
        }
    }


    if(display.properTimeFormat){
        proper = " AM ";
        if(tm.tm_hour == 0){
            tm.tm_hour = 12;
        }
        else if(tm.tm_hour > 12){
            proper = " PM ";
            tm.tm_hour -= 12;
        }
    }

    char *fmt = NULL;
    if(display.date){
        fmt = "%F %T";
    }
    else{
        fmt = "%T";
    }
    result = strftime(timeStr, len, fmt, &tm);
    if(result == 0){
        return -4;
    }
    len -= result - 1;

    if(display.timezone){
        result = snprintf(&timeStr[strlen(timeStr)], len, ".%03ld%s%s",
                          ts.tv_nsec / 1000000, proper,
                          tzEnum == LOGC4_TZ_LOCAL ?
                          tzname[daylight != 0] : UTCStr);
    }
    else{
        result = snprintf(&timeStr[strlen(timeStr)], len, ".%03ld%s",
                          ts.tv_nsec / 1000000, proper);
    }
    if(result >= len){
        return -5;
    }

    return 0;
}

/**
  * @brief This gets the current time string according to the given timezone.
  *
  * @param timezone The timezone to use when getting the time string.
  * @param display The @a logc4_display_t struct that is used to determine
  * what information to display.
  * @param fileName The name of the file that is calling this function. Can be
  * @a NULL.
  * @param funcName The name of the function that is calling this function. Can
  * be @a NULL.
  * @return char* The formatted timezone string.
*/
static char *getCurrentTime(const logc4_tz_t timezone, logc4_display_t display,
                            const char *fileName, const char *funcName){
    char *timeStr = calloc(TIME_STR_LEN, sizeof(char));
    timeCheckAlloc(timeStr, __func__, __LINE__ - 1, 2, fileName, funcName);
    int ret = getCurrentTimeFromTimeSpec(timeStr, TIME_STR_LEN, timezone,
                                         display);
    int lineNumber = __LINE__ - 2;
    if(ret != 0){
        int ref = 0;
        if(fileName == NULL && funcName != NULL){
            ref = 2;
        }
        else if(fileName != NULL && funcName == NULL){
            ref = 1;
        }
        if(fileName == NULL && funcName == NULL){
            fprintf(stderr,
                    "%s [ERROR]{%s/%s:%d} The function "
                    "getCurrentTimeFromTimeSpec(3) returned a value of %d.\n",
                    c_NULL, __FILE__, __func__, lineNumber, ret);
        }
        else if(ref == 0){
            fprintf(stderr,
                    "%s [ERROR](%s/%s){%s/%s:%d} The function "
                    "getCurrentTimeFromTimeSpec(3) returned a value of %d\n",
                    c_NULL, fileName, funcName, __FILE__, __func__, lineNumber,
                    ret);
        }
        else{
            fprintf(stderr,
                    "%s [ERROR](%s){%s/%s:%d} The function "
                    "getCurrentTimeFromTimeSpec(3) returned a value of %d\n",
                    c_NULL, ref == 1 ? fileName : funcName, __FILE__, __func__,
                    lineNumber, ret);
        }
        char *null = calloc(c_NULL_LEN + 1, sizeof(char));
        timeCheckAlloc(null, __func__, __LINE__ - 1, 2, fileName, funcName);
        strncat(null, c_NULL, c_NULL_LEN);
        return null;
    }
    return timeStr;
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
  * @param fileName The name of the file that is calling this function. Can be
  * @a NULL.
  * @param funcName The name of the function that is calling this function. Can
  * be @a NULL.
*/
static void checkAlloc(const void *ptr, const char *intFuncName,
                       const int lineNumber, const int allocFunc,
                       const char *fileName, const char *funcName){
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
        char *time = getCurrentTime(STDLOG.timezone, STDLOG.display, NULL,
                                    NULL);
        int ref = 0;
        if(fileName == NULL && funcName != NULL){
            ref = 2;
        }
        else if(fileName != NULL && funcName == NULL){
            ref = 1;
        }
        if(fileName == NULL && funcName == NULL){
            fprintf(stderr,
                    "%s [ERROR]{%s/%s:%d} Memory allocation "
                    "function '%salloc()' failed to allocate memory.\n",
                    time, __FILE__, intFuncName, lineNumber, alloc);
        }
        else if(ref == 0){
            fprintf(stderr,
                    "%s [ERROR](%s/%s){%s/%s:%d} Memory allocation "
                    "function '%salloc()' failed to allocate memory.\n",
                    time, fileName, funcName, __FILE__, intFuncName,
                    lineNumber, alloc);
        }
        else{
            fprintf(stderr,
                    "%s [ERROR](%s){%s/%s:%d} Memory allocation "
                    "function '%salloc()' failed to allocate memory.\n",
                    time, ref == 1 ? fileName : funcName, __FILE__,
                    intFuncName, lineNumber, alloc);
        }
        free(time);
    }
}

/*
Init stdout and stderr:
- timezone
- display
*/
void logc4_stdInit(logc4_tz_t timezone, logc4_display_t display){
    STDLOG.timezone = timezone;
    STDLOG.display = display;
}

/* Gets the string representation of the logc4_msg*/
static char *getMsgType(const logc4_msg_t msgType){
    switch(msgType){
        case LOGC4_MSG_ERROR:
            return "ERROR";
        case LOGC4_MSG_WARNING:
            return "WARNING";
        case LOGC4_MSG_INFO:
            return "INFO";
#ifdef LOGC4_DEBUG_PROG
        case LOGC4_MSG_DEBUG:
            return "DEBUG";
#endif
        default:
            return "UNKNOWN";
    }
}

/*
Log formatted message to stdout or stderr from the given format string and
function values.
*/
int logc4_stdLog(const logc4_msg_t msgType, const bool toStderr,
                 const char *fileName, const char *funcName,
                 const char *format, ...){
    FILE *outFile = toStderr ? stderr : stdout;
    int result = -1;
    char *buffer = calloc(1, sizeof(char));
    checkAlloc(buffer, __func__, __LINE__ - 1, 2, NULL, NULL);

    va_list args;
    va_start(args, format);
    result = vsnprintf(buffer, 1, format, args);
    va_end(args);

    free(buffer);
    buffer = calloc(result + 1, sizeof(char));

    va_start(args, format);
    vsnprintf(buffer, result + 1, format, args);
    va_end(args);

    char *type = getMsgType(msgType);
    char *time = getCurrentTime(STDLOG.timezone, STDLOG.display, NULL,
                                NULL);
    int ref = 0;
    if(fileName == NULL && funcName != NULL){
        ref = 2;
    }
    else if(fileName != NULL && funcName == NULL){
        ref = 1;
    }
    if(fileName == NULL && funcName == NULL){
        fprintf(outFile,
                "%s [%s] %s\n",
                time, type, buffer);
    }
    else if(ref == 0){
        fprintf(outFile,
                "%s [%s](%s/%s) %s\n",
                time, type, fileName, funcName, buffer);
    }
    else{
        fprintf(outFile,
                "%s [%s](%s) %s\n",
                time, type, ref == 1 ? fileName : funcName, buffer);
    }
    free(time);
    free(buffer);
    return result;
}

/**
  * @brief Gets the full absolute path of the given relative/symbolic path.
  *
  * If there was a problem allocating memory to get the full path, then this
  * returns @a NULL instead.
  *
  * @param relPath The relative/symbolic path.
  * @return char* The full path if possible. Otherwise, @a NULL.
*/
static char *getFullFilePath(const char *relPath){
    char *rp = realpath(relPath, NULL);
    int lineNumber = __LINE__ - 1;
    checkAlloc(rp, __func__, lineNumber, 1, NULL, NULL);
    char *errStr = NULL;
    switch(errno){
        case EACCES:
            errStr = "Read or search permission was denied for a component of "
                "the path prefix.";
            break;
        case EIO:
            errStr = "An I/O error occurred while reading from the "
                "filesystem.";
            break;
        case ELOOP:
            errStr = "Too many symbolic links were encountered in translating "
                "the pathname.";
            break;
        case ENAMETOOLONG:
            errStr = "A component of a pathname exceeded NAME_MAX characters, "
                "or an entire pathname exceeded PATH_MAX characters.";
            break;
        case ENOENT:
            fclose(fopen(relPath, "w"));
            return getFullFilePath(relPath);
        case ENOTDIR:
            errStr = "A component of the path prefix is not a directory.";
            break;
        default:
            // Do nothing if any other value.
            break;
    }
    char *time = getCurrentTime(STDLOG.timezone, STDLOG.display, NULL,
                                NULL);
    fprintf(stderr,
            "%s [ERROR]{%s/%s:%d} The function realpath(3) failed with the "
            "following message: %s\n",
            time, __FILE__, __func__, lineNumber, errStr);
    free(time);
    return rp;
}

/* Opens a log file with the given file path. */
logc4_file_t *logc4_fileOpen(const char *filePath, const bool append,
                             const logc4_tz_t timezone,
                             const logc4_display_t display){
    if(filePath == NULL){
        return NULL;
    }
    logc4_file_t *fd = malloc(sizeof(logc4_file_t));
    fd->filePath = getFullFilePath(filePath);
    if(fd->filePath == NULL){
        return NULL;
    }
    if(append){
        fd->file = fopen(fd->filePath, "a");
    }
    else{
        fd->file = fopen(fd->filePath, "w");
    }
    fd->timezone = timezone;
    fd->display = display;
    return fd;
}

/* Closes the given log file. */
void logc4_fileClose(logc4_file_t *logFile){
    if(logFile != NULL){
        fclose(logFile->file);
        logFile->file = NULL;
        free(logFile->filePath);
        logFile->filePath = NULL;
        logFile->timezone = 0;
        logFile->display = (logc4_display_t){0};
        free(logFile);
        logFile = NULL;
    }
}

/*
Logs the given normal or wide-character format string with the given
variables substituted.
*/
int logc4_fileLog(const logc4_file_t *logFile, const logc4_msg_t msgType,
                  const char *fileName, const char *funcName,
                  const char *format, ...){
    int result = -1;
    char *buffer = calloc(1, sizeof(char));
    checkAlloc(buffer, __func__, __LINE__ - 1, 2, NULL, NULL);

    va_list args;
    va_start(args, format);
    result = vsnprintf(buffer, 1, format, args);
    va_end(args);

    free(buffer);
    buffer = calloc(result + 1, sizeof(char));

    va_start(args, format);
    vsnprintf(buffer, result + 1, format, args);
    va_end(args);

    char *type = getMsgType(msgType);
    char *time = getCurrentTime(logFile->timezone, logFile->display, fileName,
                                funcName);
    int ref = 0;
    if(fileName == NULL && funcName != NULL){
        ref = 2;
    }
    else if(fileName != NULL && funcName == NULL){
        ref = 1;
    }
    if(fileName == NULL && funcName == NULL){
        fprintf(logFile->file,
                "%s [%s] %s\n",
                time, type, buffer);
    }
    else if(ref == 0){
        fprintf(logFile->file,
                "%s [%s](%s/%s) %s\n",
                time, type, fileName, funcName, buffer);
    }
    else{
        fprintf(logFile->file,
                "%s [%s](%s) %s\n",
                time, type, ref == 1 ? fileName : funcName, buffer);
    }
    free(time);
    free(buffer);
    return result;
}

#undef TIME_STR_LEN
#undef c_NULL
#undef c_NULL_LEN
