/**
  * @file logc4.h
  * @author CodexUniversalis (codexuniversalisprime@gmail.com)
  * @brief The header file for the @a Logc4 library.
  * @version 0.1.0
  * @date 2025-04-24: Created. @n @n
  * Changelog
  * - 2025-04-24: Refactored file from previous failed project.
  * - 2025-04-26: Changed a couple of comments.
  * - 2025-05-01: Fixed file comments and added logc4_stdInit().
  * Github <a href="@ghc/038b3387d1b05ff13556ba55e1489a5ac00d3af6">commit</a>.
  * - 2025-05-03: Implemented mostly old code.
  * Github <a href="@ghc/a2efdfb47228bbfdde5f36d7bd668304dfdc19b9">commit</a>.
  * - 2025-05-19: Reworked some of the functions and removed unneeded structs.
  * Github <a href="@ghc/78f4278d8c60d382af35c1e65b7597f3d487d286">commit</a>.
  * - 2025-05-20: Refactor some function headers.
  * Github <a href="@ghc/ea353fd037a713db521b873883e769dd967106a1">commit</a>.
  * - 2025-05-21: Refactor some function headers.
  * Github <a href="@ghc/1178c2d3db540b7e074684eae82cd47ca3e602a7">commit</a>.
  * - 2025-05-26: Worked on implementing timezones.
  * Github <a href="@ghc/8c747b6b07242a5cb8baaaba6b414a38047fe5e6">commit</a>.
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
typedef enum{
    /**
      * @brief The log message is of type @a ERROR.
    */
    LOGC4_ERROR,
    /**
      * @brief The log message is of type @a WARNING.
    */
    LOGC4_WARNING,
    /**
      * @brief The log message is of type @a INFO.
    */
    LOGC4_INFO,
#ifdef LOGC4_DEBUG_PROG
    /**
      * @brief The log message is of type @a DEBUG.
    */
    LOGC4_DEBUG
#endif
} logc4_msg_t;

/**
  * @brief An enum of the acceptable timezones.
  *
  * These values are taken from
  * <a href="https://www.timeanddate.com/time/zones/">timeanddate.com</a>. See
  * this for all additional information.
*/
typedef enum{
    /**
      * The timezone (@a Local) is (@a UTC+??:??:??):
      * - The local timezone of the computer.
    */
    LOGC4_TZ_LOCAL = -1,
    /**
      * The timezone (@a Universal) is (@a UTC):
      * - Coordinated Universal Time (@a UTC).
    */
    LOGC4_TZ_UTC,
    /**
      * The timezone (@a Military) is (@a UTC+1):
      * - Alfa Time Zone.
    */
    LOGC4_TZ_A,
    /**
      * The timezone (@a Australia) is (@a UTC+10:30):
      * - Australian Central Daylight Time
      * - (@a CDT) Central Daylight Time
      * - (@a CDST) Central Daylight Savings Time
    */
    LOGC4_TZ_ACDT,
    /**
      * The timezone (@a Australia) is (@a UTC+9:30):
      * - Australian Central Standard Time
      * - (@a CST) Central Setandard Timei
    */
    LOGC4_TZ_ACST,
    /**
      * The timezone (@a South America) is (@a UTC-5):
      * - Acre Time
    */
    LOGC4_TZ_ACT1,
    /**
      * The timezone (@a Australia) is (@a UTC+9:30/+10:30):
      * - Australian Central Time
    */
    LOGC4_TZ_ACT2,
    /**
      * The timezone (@a Australia) is (@a UTC+8:45):
      * - Australian Central Western Standard Time
    */
    LOGC4_TZ_ACWST,
    /**
      * The timezone (@a Asia) is (@a UTC+4):
      * - Arabia Dyalight Time
      * - (@a AST) Arabia Summer Time
    */
    LOGC4_TZ_ADT1,
    /**
      * The timezone (@a North America / Atlantic) is (@a UTC-3):
      * - Atlantic Daylight Time
      * - (@a ADST) Atlantic Daylight Saving Time
      * - (@a AST) Atlantic Summer Time
      * - (@a HAA) Heure Avancée de l'Atlantique (French)
    */
    LOGC4_TZ_ADT2,
    /**
      * The timezone (@a Australia) is (@a UTC+11):
      * - Australian Eastern Daylight Time
      * - (@a EDT) Eastern Daylight Time
      * - (@a EDST) Eastern Daylight Saving Time
    */
    LOGC4_TZ_AEDT,
    /**
      * The timezone (@a Australia) is (@a UTC+10):
      * - Australian Eastern Standard Time
      * - (@a EST) Eastern Standard Time
      * - (@a AET) Australian Eastern Time
    */
    LOGC4_TZ_AEST,
    /**
      * The timezone (@a Australia) is (@a UTC+10/11):
      * - Australian Eastern Time
    */
    LOGC4_TZ_AET,
    /**
      * The timezone (@a Asia) is (@a UTC+4:30):
      * - Afghanistan Time
    */
    LOGC4_TZ_AFT,
    /**
      * The timezone (@a North America) is (@a UTC-8):
      * - Alaska Daylight Time
      * - (@a ADST) Alaska Daylight Saving Time
    */
    LOGC4_TZ_AKDT,
    /**
      * The timezone (@a North America) is (@a UTC-9):
      * - Alaska Standard Time
      * - (@a AT) Alaska Time
    */
    LOGC4_TZ_AKST,
    /**
      * The timezone (@a Asia) is (@a UTC+6):
      * - Alma-Ata Time
    */
    LOGC4_TZ_ALMT,
    /**
      * The timezone (@a South America) is (@a UTC-3):
      * - Amazon Summer Time
    */
    LOGC4_TZ_AMST1,
    /**
      * The timezone (@a Asia) is (@a UTC+5):
      * - Armenia Summer Time
      * - (@a AMDT) Armenia Daylight Time
    */
    LOGC4_TZ_AMST2,
    /**
      * The timezone (@a South America) is (@a UTC-4):
      * - Amazon Time
    */
    LOGC4_TZ_AMT1,
    /**
      * The timezone (@a Asia) is (@a UTC+4):
      * - Armenia Time
    */
    LOGC4_TZ_AMT2,
    /**
      * The timezone (@a Asia) is (@a UTC+12):
      * - Anadyr Time
    */
    LOGC4_TZ_ANAST,
    /**
      * The timezone (@a Asia) is (@a UTC+12):
      * - Anadyr Time
    */
    LOGC4_TZ_ANAT,
    /**
      * The timezone (@a Asia) is (@a UTC+5):
      * - Aqtobe Time
    */
    LOGC4_TZ_AQTT,
    /**
      * The timezone (@a Antarctica / South America) is (@a UTC-3):
      * - Argentina Time
    */
    LOGC4_TZ_ART,
    /**
      * The timezone (@a Asia) is (@a UTC+3):
      * - Arabia Standard Time
      * - (@a AST) Arabic Standard Time
      * - (@a AST) Al Manamah Standard Time
    */
    LOGC4_TZ_AST1,
    /**
      * The timezone (@a North America / Atlantic / Caribbean) is (@a UTC-4):
      * - Atlantic Standard Time
      * - (@a AT) Atlantic Time
      * - (@a AST) Tiempo Estándar del Atlántico (Spanish)
      * - (@a HNA) Heure Normale de l'Atlantique (French)
    */
    LOGC4_TZ_AST2,
    /**
      * The timezone (@a North America / Atlantic) is (@a UTC-4/3):
      * - Atlantic Time
    */
    LOGC4_TZ_AT,
    /**
      * The timezone (@a Australia) is (@a UTC+9):
      * - Australian Western Daylight Time
      * - (@a WDT) Western Daylight Time
      * - (@a WST) Western Summer Time
    */
    LOGC4_TZ_AWDT,
    /**
      * The timezone (@a Australia) is (@a UTC+8):
      * - Australian Western Standard Time
      * - (@a WST) Western Standard Time
      * - (@a WAT) Western Australia Time
    */
    LOGC4_TZ_AWST,
    /**
      * The timezone (@a Atlantic) is (@a UTC+0):
      * - Azores Summer Time
      * - (@a AZODT) Azores Daylight Time
    */
    LOGC4_TZ_AZOST,
    /**
      * The timezone (@a Atlantic) is (@a UTC-1):
      * - Azores Time
      * - (@a AZOST) Azores Standard Time
    */
    LOGC4_TZ_AZOT,
    /**
      * The timezone (@a Asia) is (@a UTC+5):
      * - Azerbaijan Summer Time
    */
    LOGC4_TZ_AZST,
    /**
      * The timezone (@a Asia) is (@a UTC+4):
      * - Azerbaijan Time
    */
    LOGC4_TZ_AZT,
    /**
      * The timezone (@a Pacific) is (@a UTC-12):
      * - Anywhere on Earth
    */
    LOGC4_TZ_AoE
} logc4_tz_t;

/**
  * @brief Different information to display in the log message.
  *
  * If any of the members are set to @a false, then they are not displayed.
*/
typedef struct{
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
} logc4_display_t;

/**
  * @brief A struct containing all of the information for a log file.
  *
  * Contains all needed information that is needed to write to the log file.
*/
typedef struct{
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
      * The values are:
      * - @a -1 to use the computer's local time.
      * - @a 0 to use UTC time.
      *
      * > NOT YET IMPLEMENTED. This will change in the future and the timezone
      * will be able to be specified for values around the globe.
    */
    int timeZone;
    /**
      * @brief A @a logc4_display_t struct with the preferences of what to
      * display in the log message.
      *
      * If any of the members are set to @a false, then they are not displayed.
    */
    logc4_display_t display;
} logc4_file_t;

/**
  * @brief Converts a normal string (char *) to a wide character string
  * (wchar_t *). The returned string should be freen when done being used.
  *
  * @param str The normal string to convert.
  * @return wchar_t* The normal string as a wide character string.
*/
wchar_t *logc4_stowcs(char *str);

/**
  * @brief Converts a wide character string (wchar_t *) to a normal string
  * (char *). The returned string should be freen when done being used.
  *
  * @param wStr The wide character string to convert.
  * @return char* The wide character string as a normal string.
*/
char *logc4_wcstos(wchar_t *wStr);

/**
  * @brief Sets the desired character type for printing to the standard output.
  *
  * @param timeZone The desired time zone to use when printing the time to
  * either @a stdout or @a stderr.
  * @param display The @a logc4_display_t struct that is used to determine
  * what information to display.
*/
void logc4_stdInit(int timeZone, logc4_display_t display);

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
  * > ONLY UTC TIME IS DISPLAYED AT THE MOMENT. THIS WILL CHANGE.
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
  * > ONLY UTC TIME IS DISPLAYED AT THE MOMENT. THIS WILL CHANGE.
  *
  * If the file could not be open, the reason is printed to @a stderr and
  * @a NULL is returned. If the file has already been opened for logging, then
  * this function returns @a NULL.
  *
  * @param filePath The absolute/relative file path of the log file.
  * @param append @a false to overwrite and not append to the file. @a true to
  * append to the end of the file.
  * @param timeZone @a 0 to use UTC time. @a 1 to use the computer's
  * local time.
  * > This will change in the future and the timezone will be able to be
  * specified for values around the globe.
  * @param display The @a logc4_display_t struct that is used to determine
  * what information to display.
  * @return logc4_file_t* A pointer to a @a logc4_file_t struct used in
  * logging.
*/
logc4_file_t *logc4_fileOpen(const char *filePath, const bool append,
                             const int timeZone, logc4_display_t display);

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
  * > ONLY UTC TIME IS DISPLAYED AT THE MOMENT. THIS WILL CHANGE.
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
