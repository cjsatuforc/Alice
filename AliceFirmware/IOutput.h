/** @file */

#ifndef _ALICE_IOUTPUT_H_
#define _ALICE_IOUTPUT_H_

#include "AliceObject.h"

class IOutput : public AliceObject
{
  public:
    IOutput(char * name);
    virtual ~IOutput();
};

#endif
