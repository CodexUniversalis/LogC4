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
#include <logc4.h>

static bool std_char_type = false;

// Init stdout and stderr character type.
void logc4_stdInit(const bool charType){
    std_char_type = true;
}

// Log formatted message to stdout and stderr from the given charType format
// and function values .
int logc4_stdLog(const logc4_msg_t msgType, const bool charType,
                 const void *format, ...){

}
