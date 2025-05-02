/**
  * @file logc4.h
  * @author CodexUniversalis (codexuniversalisprime@gmail.com)
  * @brief The header file for the @a Logc4 library.
  * @version 0.1.0
  * @date 2025-04-24: Created @n @n
  * Changelog
  * - 2025-04-24: Refactored file from previous failed project.
  * - 2025-04-26: Changed a couple of comments.
  * - 2025-05-01: Fixed file comments and added logc4_stdInit().
  * @copyright Copyright (c) 2025
*/
#pragma once
#ifndef LOGC4_H
#define LOGC4_H

#include <stdio.h>
#include <stdbool.h>

/**
  * @brief An enum of the @a LogC4 log message types.
  *
  * The @a LogC4 log message types.
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
    /**
      * @brief The log message is of type @a DEBUG.
    */
    LOGC4_DEBUG
}logc4_msg_t;

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
      * @brief The character type of the log files.
      *
      * The available values are:
      * @a 0 (false) for normal characters. @a 1 (true) for wide characters.
    */
    bool charType;
    /**
      * @brief The timezone of the log message.
      *
      * Whether to print time as military time (24-hour time) or normal
      * time (12-hour) time. @a 0 (false) for normal (12-hour) time.
      * @a 1 (true) for military (24-hour) time.
    */
    bool timeZone;
} logc4_file_t;

/**
  * @brief Sets the desired character type for printing to the standard output.
  *
  * @param charType @a 0 (false) for normal (@a ASCII) characters.
  * @a 1 (true) for wide (@a UTF-8) characters.
*/
void logc4_stdInit(const bool charType);

/**
  * @brief Logs the @a char* format to @a stdout or @a stderr with the given
  * message type.
  *
  * Logs the given string format to @a stdout with the given message type. If
  * the given message type is @ref LOGC4_ERROR, then the log message is printed
  * to @a stderr. The filled out format string is appended to the message type
  * and date-time and printed to @a stdout.
  *
  * @param msgType A valid @a logc4_msg_t enum value. If this value is not
  * valid, then @a -1 is returned.
  * @param format The format string of the log message. This is equivalent to
  * the <a href="https://www.man7.org/linux/man-pages/man3/printf.3.html">
  * printf(3)</a> format string.
  * @param ... The variables to substitute into the format string.
*/
int logc4_stdLog(const logc4_msg_t msgType, const bool charType,
                 const void *format, ...);

/**
  * @brief Opens a log file with the given file path.
  *
  * Initialize a @a logc4_file_t with the given absolute/relative file path.
  * The path will be converted to the absolute path (if applicable). Whether to
  * append the file will also need to be decided. Also, takes in the character
  * type (normal or wide character) and whether to use military-time (24-hour
  * time) or normal time (12-hour time).
  *
  * If the file could not be open, or has already been opened for logging, then
  * this function returns @a NULL.
  *
  * @param filePath The absolute/relative file path of the log file.
  * @param append @a false to overwrite and not append to the file. @a true to
  * append to the end of the file.
  * @param charType @a false to use wide characters (@a wchar_t). @a true to
  * use normal (ASCII) characters.
  * @param timeZone @a false to use UTC time. @a true to use the computer's
  * local time. (This will change in the future and the timezone will be able
  * to be specified.)
  * @return logc4_file_t* A pointer to a @a logc4_file_t struct used in
  * logging.
*/
logc4_file_t *logc4_fileOpen(const char *filePath, const bool append,
                             const bool charType, const bool timeZone);

/**
  * @brief Closes the given log file.
  *
  * This closes the file stream and frees all allocated memory from
  * @a logc4_fileOpen(3). This also sets the given pointer to @a NULL so
  * nothing funny happens.
  *
  * @param logFile The log file to close and free.
*/
void logc4_fileClose(logc4_file_t *logFile);

/**
  * @brief Logs the given normal or wide-character format string with the given
  * variables substituted.
  *
  * The format can be either be a normal (@a char*) or wide-character
  * (@a wchar_t*) string.
  *
  * To see more information about the format string, see
  * <a href="https://www.man7.org/linux/man-pages/man3/printf.3.html">
  * printf(3)</a>.
  *
  * @param logFile The log file to print the formatted message to.
  * @param msgType The type of message to print to the log file.
  * @param format The format string of the log message. This is equivalent to
  * the <a href="https://www.man7.org/linux/man-pages/man3/printf.3.html">
  * printf(3)</a> and or the
  * <a href="https://www.man7.org/linux/man-pages/man3/wprintf.3.html">
  * wprintf(3)</a> format string.
  * @param ... The variables to substitute into the format string.
  * @return int The number of characters printed to the log file.
*/
int logc4_fileLog(const logc4_file_t *logFile, const logc4_msg_t msgType,
                  const void *format, ...);

#endif
