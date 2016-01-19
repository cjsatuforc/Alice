/** @file */

#ifndef _ALICE_PPMOUTPUT_H_
#define _ALICE_PPMOUTPUT_H_

#include "IOutput.h"

/**
 * @class PPMOutput
 * @brief Output device to output a PPM stream.
 */
class PPMOutput : public IOutput
{
  public:
    PPMOutput(char * name, channelnumber_t start, channelnumber_t end);
    virtual ~PPMOutput();
};

#endif
