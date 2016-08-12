/** @file */

#include "PPMOutput.h"

bool PPMOutput::s_streamsInUse[NUM_PPM_STREAMS] = {false};

/**
 * @copydoc IOutput::IOutput
 * @param pin Arduino pin to output CPPM stream on
 * @param logic Logic level of an active CPPM pulse
 * @param frameLength CPPM frame length in us
 * @param pulseLength CPPM pulse length in us
 */
PPMOutput::PPMOutput(char *name, channelnumber_t start, channelnumber_t end, int8_t pin,
                     uint8_t logic, uint64_t frameLength, uint64_t pulseLength)
    : IOutput(name, start, end)
    , m_streamNumber(-1)
{
  for (size_t i = 0; i < NUM_PPM_STREAMS; i++)
  {
    if (!s_streamsInUse[i])
    {
      s_streamsInUse[i] = true;
      m_streamNumber = i;
      break;
    }
  }

  if (m_streamNumber != -1)
  {
    cppm_set_stream_enable(m_streamNumber, true);
    cppm_set_stream_num_channels(m_streamNumber, numChannels());

    cppm_set_stream_pin(m_streamNumber, pin);
    cppm_set_stream_logic(m_streamNumber, logic);
    cppm_set_stream_frame_length(m_streamNumber, frameLength);
    cppm_set_stream_pulse_length(m_streamNumber, pulseLength);
  }
}

PPMOutput::~PPMOutput()
{
  s_streamsInUse[m_streamNumber] = false;
}

/**
 * @copydoc IOutput::open
 */
bool PPMOutput::open()
{
  return cppm_start();
}

/**
 * @copydoc IOutput::close
 */
bool PPMOutput::close()
{
  return cppm_stop();
}

/**
 * @copydoc IOutput::isOpen
 */
bool PPMOutput::isOpen() const
{
  return cppm_is_running();
}

/**
 * @copydoc IOutput::tx
 */
bool PPMOutput::tx()
{
  for (size_t i = 0; i < m_numChannels; i++)
    cppm_set_stream_channel(m_streamNumber, i, m_values[i]);

  return true;
}

/**
 * @brief Returns the CPPM stream number usef by this device.
 * @return Stream number
 */
int8_t PPMOutput::streamNumber() const
{
  return m_streamNumber;
}

/**
 * @brief Checks to see if the output device is a valid stream.
 * @return If output is valid
 *
 * An invalid stream is likely to be caused by no free CPPM streams in the
 * driver.
 */
bool PPMOutput::valid() const
{
  return m_streamNumber != -1;
}
