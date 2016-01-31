/** @file */

#include "IOutput.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param start First channel to include in output
 * @param end Last channel to include in output
 */
IOutput::IOutput(char *name, channelnumber_t start, channelnumber_t end)
    : AliceObject(name)
    , m_numChannels(end - start + 1)
    , m_startChannel(start)
    , m_endChannel(end)
    , m_defaultValue(1500)
{
  m_values = new usvalue_t[m_numChannels];

  for (size_t i = 0; i < m_numChannels; i++)
    m_values[i] = US_CENTRE;
}

IOutput::~IOutput()
{
  delete[] m_values;
}

/**
 * @brief Returns the number of channels output by this device.
 * @return Number of channels
 */
size_t IOutput::numChannels() const
{
  return m_numChannels;
}

/**
 * @brief Returns the first channel number output by this device.
 * @return First channel number
 */
channelnumber_t IOutput::startChannel() const
{
  return m_startChannel;
}

/**
 * @brief Returns the last channel number output by this device.
 * @return Last channel number
 */
channelnumber_t IOutput::endChannel() const
{
  return m_endChannel;
}

/**
 * @brief Sets the output values based on the output of a Mixer.
 * @param values Array of values to be set
 * @param numValues Number of values in the array
 *
 * If the number of input values is too short with respect to the range of
 * channels selected for this output then any output channels with missing
 * values take the value of m_defaultValue.
 */
void IOutput::setValues(usvalue_t *values, size_t numValues)
{
  for (channelnumber_t c = m_startChannel; c <= m_endChannel; c++)
  {
    if (c < numValues)
      m_values[c - m_startChannel] = values[c];
    else
      m_values[c - m_startChannel] = m_defaultValue;
  }
}

/**
 * @brief Gets an output value by its index in the output device.
 * @param idx Index of output channel
 * @return Value of output channel
 */
usvalue_t IOutput::valueByIndex(size_t idx) const
{
  if (idx > m_numChannels)
    return 0;

  return m_values[idx];
}

/**
 * @brief Gets an output value by its channel number.
 * @param channelNumber Channel number of output channel
 * @return Value of output channel
 */
usvalue_t IOutput::valueByChannel(channelnumber_t channelNumber) const
{
  int idx = channelNumber - m_startChannel;
  return valueByIndex(idx);
}
