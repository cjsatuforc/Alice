/*! \file */

#ifndef _ALICE_MIXEROPERATIONADD_H_
#define _ALICE_MIXEROPERATIONADD_H_

#include "IMixerOperation.h"

class MixerOperationAdd : public IMixerOperation
{
  public:
    MixerOperationAdd(char * name, char * mappedInputName, cevalue_t weight)
      : IMixerOperation(name, mappedInputName, weight)
    {
    }

    virtual ~MixerOperationAdd() {}

  protected:
    virtual cevalue_t doEvaluation(cevalue_t lastValue) const
    {
      return lastValue + (m_weight * getInputValue()) / 100.0;
    }
};

#endif
