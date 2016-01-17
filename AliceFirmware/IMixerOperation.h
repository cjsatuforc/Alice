/*! \file */

#ifndef _ALICE_IMIXEROPERATION_H_
#define _ALICE_IMIXEROPERATION_H_

#include "AliceTypes.h"
#include "AliceObject.h"

class IMixerOperation : public AliceObject
{
  public:
    IMixerOperation(char * name, char * mappedInputName, cevalue_t weight);
    virtual ~IMixerOperation();

    const char * getMappedInputName() const;

    cevalue_t getInputValue() const;
    cevalue_t evaluate(cevalue_t lastValue) const;

    cevalue_t getWeight() const;

  protected:
    virtual cevalue_t doEvaluation(cevalue_t lastValue) const = 0;

    const cevalue_t m_weight;

  private:
    const char * m_mappedInputName;
};

#endif
