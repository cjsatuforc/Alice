#ifndef _ALICE_CPPM_ENCODE_H_
#define _ALICE_CPPM_ENCODE_H_

#include "AliceTypes.h"

#define MAX_PPM_CHANNELS 8
#define NUM_PPM_STREAMS 4

void cppm_init();
bool cppm_start();
bool cppm_stop();
void cppm_isr();

bool cppm_set_stream_enable(size_t streamID, bool enable);
bool cppm_set_stream_pin(size_t streamID, uint8_t pin);
bool cppm_set_stream_num_channels(size_t streamID, size_t numChannels);
bool cppm_set_stream_logic(size_t streamID, uint8_t logic);
bool cppm_set_stream_frame_length(size_t streamID, uint64_t frameLength);
bool cppm_set_stream_pulse_length(size_t streamID, uint64_t pulseLength);
void cppm_set_stream_channel(size_t streamID, uint8_t channel, uint16_t value);

#endif
