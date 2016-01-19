/** @file */

#include "SerialOutput.h"

/**
 * @copydoc IOutput::IOutput
 */
SerialOutput::SerialOutput(char * name, channelnumber_t start, channelnumber_t end)
  : IOutput(name, start, end)
{
}

SerialOutput::~SerialOutput()
{
}
