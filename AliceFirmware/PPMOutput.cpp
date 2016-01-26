/** @file */

#include "PPMOutput.h"

/**
 * @copydoc IOutput::IOutput
 */
PPMOutput::PPMOutput(char *name, channelnumber_t start, channelnumber_t end)
    : IOutput(name, start, end)
{
}

PPMOutput::~PPMOutput()
{
}

/**
 * @copydoc IOutput::open
 */
bool PPMOutput::open()
{
}

/**
 * @copydoc IOutput::close
 */
bool PPMOutput::close()
{
}

/**
 * @copydoc IOutput::isOpen
 */
bool PPMOutput::isOpen() const
{
}

/**
 * @copydoc IOutput::tx
 */
bool PPMOutput::tx()
{
}
