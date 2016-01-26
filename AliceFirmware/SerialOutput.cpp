/** @file */

#include "SerialOutput.h"

/**
 * @copydoc IOutput::IOutput
 * @param stream Stream to output channel values to
 */
SerialOutput::SerialOutput(char *name, channelnumber_t start, channelnumber_t end,
                           const Stream &stream)
    : IOutput(name, start, end)
    , m_stream(stream)
{
}

SerialOutput::~SerialOutput()
{
}

/**
 * @copydoc IOutput::tx
 *
 * Outputs each channel value separated by a tab.
 */
bool SerialOutput::tx()
{
  for (size_t i = 0; i < m_numChannels; i++)
  {
    if (i > 0)
      Serial.print("\t");

    Serial.print(m_values[i]);
  }

  Serial.println();

  return true;
}
