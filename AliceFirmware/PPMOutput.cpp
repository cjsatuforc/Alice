/** @file */

#include "PPMOutput.h"

/**
 * @copydoc IOutput::IOutput
 */
PPMOutput::PPMOutput(char * name, channelnumber_t start, channelnumber_t end)
  : IOutput(name, start, end)
{
}

PPMOutput::~PPMOutput()
{
}
