#ifndef ALICE_PPM_H
#define ALICE_PPM_H

#include "Types.h"

void ppm_init(int pin, size_t numChannels);
int ppm_set_channel(channelid_t channel, channelvalue_t value);

#endif
