#ifndef _ALICE_IINPUT_H_
#define _ALICE_IINPUT_H_

#include "AliceTypes.h"
#include "AliceObject.h"

class IInput : public AliceObject
{
  public:
    IInput(char * name);
    virtual ~IInput();

    virtual usvalue_t value() = 0;
};

#endif
