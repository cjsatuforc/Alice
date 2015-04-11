#include "SerialLog.h"

#include "Arduino.h"


void setup_serial_logger()
{
#if ALICE_SERIAL_LOG_LEVEL > -1
  ALICE_LOG_SERIAL_PORT.begin(ALICE_LOG_SERIAL_BAUD);
  info("Log opened");
#endif
}


void error(const char * msg)
{
#if ALICE_SERIAL_LOG_LEVEL >= 3
  ALICE_LOG_SERIAL_PORT.print("ERROR: ");
  ALICE_LOG_SERIAL_PORT.println(msg);
#endif
}


void warn(const char * msg)
{
#if ALICE_SERIAL_LOG_LEVEL >= 2
  ALICE_LOG_SERIAL_PORT.print("WARN: ");
  ALICE_LOG_SERIAL_PORT.println(msg);
#endif
}


void info(const char * msg)
{
#if ALICE_SERIAL_LOG_LEVEL >= 1
  ALICE_LOG_SERIAL_PORT.print("INFO: ");
  ALICE_LOG_SERIAL_PORT.println(msg);
#endif
}


void debug(const char * msg)
{
#if ALICE_SERIAL_LOG_LEVEL >= 0
  ALICE_LOG_SERIAL_PORT.print("DEBUG: ");
  ALICE_LOG_SERIAL_PORT.println(msg);
#endif
}
