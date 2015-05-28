#include "PPMRadio.h"

#include "ppm.h"


PPMRadio::PPMRadio(int pin, size_t numChannels) : IRadio()
{
  ppm_init(pin, numChannels);
}


bool PPMRadio::setChannel(channelid_t id, channelvalue_t value)
{
  return !ppm_set_channel(id, value);
}
