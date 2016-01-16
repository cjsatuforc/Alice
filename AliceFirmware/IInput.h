#ifndef _ALICE_IINPUT_H_
#define _ALICE_IINPUT_H_

#include "AliceTypes.h"

class IInput
{
  public:
    IInput();
    virtual ~IInput();

    virtual channelvalue_t value() = 0;
};

#endif
