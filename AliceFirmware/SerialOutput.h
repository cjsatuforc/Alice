#ifndef _ALICE_SERIALOUTPUT_H_
#define _ALICE_SERIALOUTPUT_H_

#include "IOutput.h"

class SerialOutput : public IOutput
{
  public:
    SerialOutput(char * name);
    virtual ~SerialOutput();
};

#endif
