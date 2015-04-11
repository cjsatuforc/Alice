#ifndef ALICE_SERIAL_LOG_H
#define ALICE_SERIAL_LOG_H


#ifndef ALICE_SERIAL_LOG_LEVEL
#define ALICE_SERIAL_LOG_LEVEL 1
#endif

#ifndef ALICE_LOG_SERIAL_PORT
#define ALICE_LOG_SERIAL_PORT Serial
#endif

#ifndef ALICE_LOG_SERIAL_BAUD
#define ALICE_LOG_SERIAL_BAUD 115200
#endif


void setup_serial_logger();

void error(const char * msg);
void warn(const char * msg);
void info(const char * msg);
void debug(const char * msg);

#endif
