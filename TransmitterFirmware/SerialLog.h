#ifndef ALICE_SERIAL_LOG_H
#define ALICE_SERIAL_LOG_H

#define ALICE_SERIAL_LOG_LEVEL 0
#define ALICE_LOG_SERIAL_PORT Serial
#define ALICE_LOG_SERIAL_BAUD 115200

void setup_serial_logger();

void error(const char * msg);
void warn(const char * msg);
void info(const char * msg);
void debug(const char * msg);

#endif
