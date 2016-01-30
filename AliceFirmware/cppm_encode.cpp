/** @file */

#include "cppm_encode.h"

#include <TimerThree.h>

/**
 * @def TIMER
 * @brief The timer in use for triggering the CPPM ISR.
 */
#define TIMER Timer3

/**
 * @brief True if the timer has been started for CPPM ISR.
 */
bool cppm_running = false;

/**
 * @brief Holds state of each CPPM stream.
 */
volatile struct
{
  bool enable; //!< Flag to indicate this stream is active and should be output
  int8_t pin; //!< Pin this stream outputs on
  usvalue_t values[MAX_PPM_CHANNELS]; //!< Values (in us) for channels
  size_t num_channels; //!< Number of active channels on this stream
  uint64_t frame_length; //!< Length of a frame in us
  uint64_t pulse_length; //!< Length of a channel marker pulse in us
  uint8_t logic; //!< Active logic level

  uint8_t channel; //!< Current channel being output in ISR
  uint64_t frame_start_time; //!< Start of frame in us in ISR
  uint64_t channel_start_time; //!< Start of channel pulse in us in ISR
} cppm_streams[NUM_PPM_STREAMS];

/**
 * @brief Initializes the CPPM driver and assigns reasonable initial values to
 *        the configuration.
 */
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

/**
 * @brief Starts the CPPM driver.
 * @return True if the CPPM driver was started successfully, false otherwise
 * @see cppm_stop()
 *
 * No further configuration changes may be made until cppm_stop() is called.
 */
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

/**
 * @brief Stops the CPPM driver.
 * @return True if the CPPM driver was stopped successfully, false otherwise
 * @see cppm_start()
 */
bool cppm_stop()
{
  if (!cppm_running)
    return false;

  TIMER.stop();

  cppm_running = false;
  return true;
}

/**
 * @brief CPPM ISR, called by the TIMER.
 */
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

/**
 * @brief Enables or disables output of a given CPPM stream.
 * @param streamID Stream number
 * @param enable If the stream should be output
 * @return True if configuration was set, false otherwise
 * @see cppm_stop()
 *
 * CPPM output must be stopped before configuration changes can be made.
 */
bool cppm_set_stream_enable(size_t streamID, bool enable)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].enable = enable;
  interrupts();

  return true;
}

/**
 * @brief Sets the pin that the CPPM stream will be output on.
 * @param streamID Stream number
 * @param pin Arduino pin number
 * @return True if configuration was set, false otherwise
 * @see cppm_stop()
 *
 * CPPM output must be stopped before configuration changes can be made.
 */
bool cppm_set_stream_pin(size_t streamID, uint8_t pin)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].pin = pin;
  interrupts();

  return true;
}

/**
 * @brief Sets the number of active channels on a given CPPM stream.
 * @param streamID Stream number
 * @param numChannels Number of active channels
 * @return True if configuration was set, false otherwise
 * @see cppm_stop()
 *
 * CPPM output must be stopped before configuration changes can be made.
 */
bool cppm_set_stream_num_channels(size_t streamID, size_t numChannels)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].num_channels = numChannels;
  interrupts();

  return true;
}

/**
 * @brief Sets the logic direction for CPPM pulses.
 * @param streamID Stream number
 * @param logic Active logic level.
 * @return True if configuration was set, false otherwise
 * @see cppm_stop()
 *
 * Set logic level will be the logic level used for the channel marker pulses.
 *
 * CPPM output must be stopped before configuration changes can be made.
 */
bool cppm_set_stream_logic(size_t streamID, uint8_t logic)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].logic = logic;
  interrupts();

  return true;
}

/**
 * @brief Sets the length of a CPPM frame in microseconds.
 * @param streamID Stream number
 * @param frameLength Frame length in us
 * @return True if configuration was set, false otherwise
 * @see cppm_stop()
 *
 * CPPM output must be stopped before configuration changes can be made.
 */
bool cppm_set_stream_frame_length(size_t streamID, uint64_t frameLength)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].frame_length = frameLength;
  interrupts();

  return true;
}

/**
 * @brief Sets the length of a channel marker pulse in microseconds.
 * @param streamID Stream number
 * @param pulseLength Pulse length in us
 * @return True if configuration was set, false otherwise
 * @see cppm_stop()
 *
 * CPPM output must be stopped before configuration changes can be made.
 */
bool cppm_set_stream_pulse_length(size_t streamID, uint64_t pulseLength)
{
  if (cppm_running)
    return false;

  noInterrupts();
  cppm_streams[streamID].pulse_length = pulseLength;
  interrupts();

  return true;
}

/**
 * @brief Sets the value of a channel of a given stream.
 * @param streamID Stream number
 * @param channel Channel number
 * @param value New value for the channel (between 1000 and 2000)
 */
void cppm_set_stream_channel(size_t streamID, uint8_t channel, usvalue_t value)
{
  noInterrupts();
  cppm_streams[streamID].values[channel] = value;
  interrupts();
}
