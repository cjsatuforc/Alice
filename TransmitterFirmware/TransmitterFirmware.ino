#include <inttypes.h>

#include "SerialLog.h"
#include "IRadio.h"
#include "IChannel.h"


IChannel chans[] = {
  IChannel("Test One", 0, 0, 1500, 2500)
};


void setup()
{
  setup_serial_logger();

  info(chans[0].getName());
}


void loop()
{
}
