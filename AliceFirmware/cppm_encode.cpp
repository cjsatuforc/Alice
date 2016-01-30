#include "cppm_encode.h"

#include <TimerThree.h>
#define TIMER Timer3

bool cppm_running = false;

volatile struct
{
  bool enable;
  int8_t pin;
  uint16_t values[MAX_PPM_CHANNELS];
  size_t num_channels;
  uint64_t frame_length;
  uint64_t pulse_length;
  uint8_t logic;
  uint8_t channel;
  uint64_t frame_start_time;
  uint64_t channel_start_time;
} cppm_streams[NUM_PPM_STREAMS];

void cppm_init()
{
  cppm_stop();

  /* Default config values */
  for (size_t i = 0; i < NUM_PPM_STREAMS; i++)
  {
    cppm_streams[i].enable = false;
    cppm_streams[i].pin = -1;
    cppm_streams[i].num_channels = 4;
    cppm_streams[i].frame_length = 22500;
    cppm_streams[i].pulse_length = 300;
    cppm_streams[i].logic = LOW;

    for (size_t j = 0; j < MAX_PPM_CHANNELS; j++)
      cppm_streams[i].values[j] = 1500;
  }
}

bool cppm_start()
{
  if (cppm_running)
    return false;

  for (size_t i = 0; i < NUM_PPM_STREAMS; i++)
  {
    if (!cppm_streams[i].enable || cppm_streams[i].pin == -1)
      continue;

    pinMode(cppm_streams[i].pin, OUTPUT);
    digitalWrite(cppm_streams[i].pin, cppm_streams[i].logic);

    cppm_streams[i].channel = cppm_streams[i].num_channels;
  }

  /* Setup timer */
  TIMER.initialize(2);
  TIMER.attachInterrupt(cppm_isr);

  cppm_running = true;
  return true;
}

bool cppm_stop()
{
  if (!cppm_running)
    return false;

  TIMER.stop();

  cppm_running = false;
  return true;
}

void cppm_isr()
{
  uint32_t t = micros();

  for (size_t i = 0; i < NUM_PPM_STREAMS; i++)
  {
    if (!cppm_streams[i].enable)
      continue;

    if (digitalRead(cppm_streams[i].pin) == !cppm_streams[i].logic &&
        cppm_streams[i].channel == cppm_streams[i].num_channels)
    {
      /* Wait for end of frame */
      if (t - cppm_streams[i].frame_start_time < 22500)
        continue;

      cppm_streams[i].frame_start_time = t;
      cppm_streams[i].channel_start_time = t;
      cppm_streams[i].channel = 0;
    }

    uint32_t channel_pulse_time = t - cppm_streams[i].channel_start_time;

    /* End of channel time */
    if (cppm_streams[i].channel < cppm_streams[i].num_channels &&
        channel_pulse_time > cppm_streams[i].values[cppm_streams[i].channel])
    {
      cppm_streams[i].channel_start_time = t;
      cppm_streams[i].channel++;
      channel_pulse_time = 0;
    }

    /* Start of channel pulse */
    if (channel_pulse_time == 0)
      digitalWrite(cppm_streams[i].pin, cppm_streams[i].logic);

    /* End of channel pulse */
    else if (channel_pulse_time > 300)
      digitalWrite(cppm_streams[i].pin, !cppm_streams[i].logic);
  }
}

bool cppm_set_stream_enable(size_t streamID, bool enable)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].enable = enable;
  interrupts();

  return true;
}

bool cppm_set_stream_pin(size_t streamID, uint8_t pin)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].pin = pin;
  interrupts();

  return true;
}

bool cppm_set_stream_num_channels(size_t streamID, size_t numChannels)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].num_channels = numChannels;
  interrupts();

  return true;
}

bool cppm_set_stream_logic(size_t streamID, uint8_t logic)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].logic = logic;
  interrupts();

  return true;
}

bool cppm_set_stream_frame_length(size_t streamID, uint64_t frameLength)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].frame_length = frameLength;
  interrupts();

  return true;
}

bool cppm_set_stream_pulse_length(size_t streamID, uint64_t pulseLength)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].pulse_length = pulseLength;
  interrupts();

  return true;
}

void cppm_set_stream_channel(size_t streamID, uint8_t channel, uint16_t value)
{
  noInterrupts();
  cppm_streams[streamID].values[channel] = value;
  interrupts();
}
