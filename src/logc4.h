/**
  * @file logc4.h
  * @author CodexUniversalis (codexuniversalisprime@gmail.com)
  * @brief The header file for the @a Logc4 library.
  *
  * For proper handling of @a UTF-8 characters, ensure that
  * <i>setlocale(LC_ALL, "en_US,UTF-8")</i> is called before using this
  * library.
  *
  * @version 0.1.0
  * @date 2025-04-24: Created. @n @n
  * Changelog
  * - 2025-04-24: Refactored file from previous failed project.
  * - 2025-04-26: Changed a couple of comments.
  * - 2025-05-01: Fixed file comments and added logc4_stdInit().
  * GitHub <a href="@ghc/038b3387d1b05ff13556ba55e1489a5ac00d3af6">commit</a>.
  * - 2025-05-03: Implemented mostly old code.
  * GitHub <a href="@ghc/a2efdfb47228bbfdde5f36d7bd668304dfdc19b9">commit</a>.
  * - 2025-05-19: Reworked some of the functions and removed unneeded structs.
  * GitHub <a href="@ghc/78f4278d8c60d382af35c1e65b7597f3d487d286">commit</a>.
  * - 2025-05-20: Refactor some function headers.
  * GitHub <a href="@ghc/ea353fd037a713db521b873883e769dd967106a1">commit</a>.
  * - 2025-05-21: Refactor some function headers.
  * GitHub <a href="@ghc/1178c2d3db540b7e074684eae82cd47ca3e602a7">commit</a>.
  * - 2025-05-26: Worked on implementing timezones.
  * GitHub <a href="@ghc/8c747b6b07242a5cb8baaaba6b414a38047fe5e6">commit</a>.
  * - 2025-05-31: Made sure GitHub was spelled correctly.
  * GitHub <a href="@ghc/e541157c808a9a20a7b611e696840db7d67d443e">commit</a>.
  * - 2025-06-08: Removed the timezone enum from this file and moved it to
  * @a timezones.h. Also renamed some instances of @a timeZone to @a timezone.
  * GitHub <a href="@ghc/0c3f0c205507cf393e7a22e89a5bf8fd1aa9afe7">commit</a>.
  * - 2025-06-15: The only timezones are @a LOGC4_TZ_LOCAL and @a LOGC4_TZ_UTC.
  * Also added the ability to convert from communist (24-hour) to
  * proper (12-hour) format.
  * GitHub <a href="@ghc/cb907a7e6fd9236ef1244a7818c49f0a2b8126b7">commit</a>.
  * - 2025-06-15: Updated comments for files.
  * GitHub <a href="@ghc/525644530ddb5cba5235f930ecbfd615283f1296">commit</a>.
  * - 2025-06-16: Removed the logc4_stowcs() and logc4_wcstos() functions.
  * Github <a href="@ghc/28e89b59e944fecf5a74264726772faf85e29143">commit</a>.
  * - 2025-06-19: Changed the file comment.
  * Github <a href="@ghc/6e4e54ceb18ae90967fd68c6beaba373717fbed6">commit</a>.
  * - 2025-06-25: Making public.
  * Github <a href="@ghc/a011d39fe5e2ef9db0c7e1038b50450a7774a06e"></a>.
  * @copyright Copyright (c) 2025
*/
#pragma once
#ifndef LOGC4_H
#define LOGC4_H

#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>

// TODO: MAKE THREAD SAFE.

/**
  * @brief An enum of the @a LogC4 log message types.
*/
typedef enum logc4_msg_t{
    /**
      * @brief The log message is of type @a ERROR.
    */
    LOGC4_MSG_ERROR,
    /**
      * @brief The log message is of type @a WARNING.
    */
    LOGC4_MSG_WARNING,
    /**
      * @brief The log message is of type @a INFO.
    */
    LOGC4_MSG_INFO,
#ifdef LOGC4_DEBUG_PROG
    /**
      * @brief The log message is of type @a DEBUG.
    */
    LOGC4_MSG_DEBUG,
#endif
#ifdef LOGC4_TEST_PROG
    /**
      * @brief The log message is of type @a TEST.
    */
    LOGC4_MSG_TEST,
#endif
} logc4_msg_t;

/**
  * @brief Different information to display in the log message.
  *
  * If any of the members are set to @a false, then they are not displayed.
*/
typedef struct logc4_display_t{
    /**
      * @brief Whether to display the calender date in the time part of the
      * log message.
      *
      * @a true to display it, @a false otherwise.
    */
    bool date;
    /**
      * @brief Whether to display the timezone in the time part of the log
      * message.
      *
      * @a true to display it, @a false otherwise.
    */
    bool timezone;
    /**
      * @brief Whether to display the time as proper (12-hour) or as
      * communist (24-hr).
      *
      * @a true to use the proper format, @a false otherwise.
      *
    */
    bool properTimeFormat;
} logc4_display_t;

/**
  * @brief An enum of the acceptable timezones.
  *
  * The only acceptable timezones are local and @a UTC.
*/
typedef enum logc4_tz_t{
    /**
      * The local timezone.
    */
    LOGC4_TZ_LOCAL = -1,
    /**
      * The timezone for <i>Coordinated Universal Time</i>.
    */
    LOGC4_TZ_UTC
} logc4_tz_t;

/**
  * @brief A struct containing all of the information for a log file.
  *
  * Contains all needed information that is needed to write to the log file.
*/
typedef struct logc4_file_t{
    /**
      * @brief The @a FILE* struct of the log file.
      *
      * The file pointer that is used when writing to the log file.
    */
    FILE *file;
    /**
      * @brief The absolute path of the log file.
      *
      * The absolute path of the log file.
    */
    char *filePath;
    /**
      * @brief The timezone of the log message.
      *
      * The values are @a LOGC4_TZ_LOCAL, to use the computer's local time, and
      * @a LOGC4_TZ_UTC, to use UTC time.
    */
    logc4_tz_t timezone;
    /**
      * @brief A @a logc4_display_t struct with the preferences of what to
      * display in the log message.
      *
      * If any of the members are set to @a false, then they are not displayed.
    */
    logc4_display_t display;
} logc4_file_t;

/**
  * @brief Sets the desired character type for printing to the standard output.
  *
  * @param timeZone The timezone of the log message. @a LOGC4_TZ_LOCAL to use
  * the computer's local time. @a LOGC4_TZ_UTC to use UTC time.
  * @param display The @a logc4_display_t struct that is used to determine
  * what information to display.
*/
void logc4_stdInit(logc4_tz_t timeZone, logc4_display_t display);

/**
  * @brief Logs the formatted message to @a stdout or @a stderr with the given
  * message type.
  *
  * Logs the given string format to @a stdout with the given message type. If
  * printing to @a stderr is wanted, then @a toStdErr argument must be @a true.
  * If your own file name and/or function name is wanted to be printed with the
  * log, then they can be passed in. If @a NULL is passed then that argument is
  * ignored and not present in the log message. The filled out format string is
  * appended to the message type and date-time and printed to @a stdout.
  *
  * To see more information about the format string, see
  * <a href="https://www.man7.org/linux/man-pages/man3/printf.3.html">
  * printf(3)</a>.
  *
  * @param msgType A valid @a logc4_msg_t enum value. If not valid, then @a -1
  * is returned.
  * @param toStderr @a true if the message should be logged to @a stderr.
  * @a false to log to @a stdout.
  * @param fileName The name of the file that is calling this function. Can be
  * @a NULL.
  * @param funcName The name of the function that is calling this function. Can
  * be @a NULL.
  * @param format The format string of the log message. This is equivalent to
  * the <a href="https://www.man7.org/linux/man-pages/man3/printf.3.html">
  * printf(3)</a> format string.
  * @param ... The variables to substitute into the format string.
*/
int logc4_stdLog(const logc4_msg_t msgType, const bool toStderr,
                 const char *fileName, const char *funcName,
                 const char *format, ...);

/**
  * @brief Opens a log file with the given file path.
  *
  * Initialize a @a logc4_file_t with the given absolute/relative file path.
  * The path will be converted to the absolute path (if applicable). Whether to
  * append the file will also need to be decided. Also, takes in the desired
  * timezone designation string.
  *
  * If the file could not be open, the reason is printed to @a stderr and
  * @a NULL is returned. If the file has already been opened for logging, then
  * this function returns @a NULL.
  *
  * @param filePath The absolute/relative file path of the log file.
  * @param append @a false to overwrite and not append to the file. @a true to
  * append to the end of the file.
  * @param timeZone @a logc4_tz_local to use the computer's local time.
  * @a logc4_tz_utc to use UTC time.
  * @param display The @a logc4_display_t struct that is used to determine
  * what information to display.
  * @return logc4_file_t* A pointer to a @a logc4_file_t struct used in
  * logging.
*/
logc4_file_t *logc4_fileOpen(const char *filePath, const bool append,
                             const logc4_tz_t timeZone,
                             const logc4_display_t display);

/**
  * @brief Closes the given log file.
  *
  * This closes the file stream and frees all allocated memory from
  * @a logc4_fileOpen(3). This also sets the given pointer to @a NULL so
  * nothing funny happens. If passed @a NULL, then nothing happens.
  *
  * @param logFile The log file to close and free.
*/
void logc4_fileClose(logc4_file_t *logFile);

/**
  * @brief Logs the formatted string to the given log file.
  *
  * Logs the given string format to the log file with the given message type.
  * If printing to @a stderr is wanted, then @a toStdErr argument must be
  * @a true. If your own file name and/or function name is wanted to be printed
  * with the log, then they can be passed in. If @a NULL is passed then that
  * argument is ignored and not present in the log message. The filled out
  * format string is appended to the message type and date-time and printed to
  * @a stdout.
  *
  * To see more information about the format string, see
  * <a href="https://www.man7.org/linux/man-pages/man3/printf.3.html">
  * printf(3)</a>.
  *
  * @param logFile The log file to print the formatted message to.
  * @param msgType The type of message to print to the log file.
  * @param fileName The name of the file that is calling this function. Can be
  * @a NULL.
  * @param funcName The name of the function that is calling this function. Can
  * be @a NULL.
  * @param format The format string of the log message. This is equivalent to
  * the <a href="https://www.man7.org/linux/man-pages/man3/printf.3.html">
  * printf(3)</a> format string.
  * @param ... The variables to substitute into the format string.
  * @return int The number of characters printed to the log file.
*/
int logc4_fileLog(const logc4_file_t *logFile, const logc4_msg_t msgType,
                  const char *fileName, const char *funcName,
                  const char *format, ...);

#endif
