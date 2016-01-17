/*! \file */

#ifndef _ALICE_IMIXEROPERATION_H_
#define _ALICE_IMIXEROPERATION_H_

#include "AliceTypes.h"
#include "AliceObject.h"

class IMixerOperation : public AliceObject
{
  public:
    IMixerOperation(char * name, char * mappedInputName);
    virtual ~IMixerOperation();

    char * getMappedInputName();

    usvalue_t getInputValue();
    virtual usvalue_t evaluate(usvalue_t lastValue) = 0;

  private:
    char * m_mappedInputName;
};

#endif
