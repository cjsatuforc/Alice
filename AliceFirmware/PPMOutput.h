/** @file */

#ifndef _ALICE_PPMOUTPUT_H_
#define _ALICE_PPMOUTPUT_H_

#include "IOutput.h"

class PPMOutput : public IOutput
{
  public:
    PPMOutput(char * name);
    virtual ~PPMOutput();
};

#endif
