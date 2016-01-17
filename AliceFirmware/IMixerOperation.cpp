/*! \file */

#include "IMixerOperation.h"

#include "InputManager.h"
#include "IInput.h"

IMixerOperation::IMixerOperation(char * name, char * mappedInputName, cevalue_t weight)
  : AliceObject(name)
  , m_mappedInputName(mappedInputName)
  , m_weight(weight)
{
}

IMixerOperation::~IMixerOperation()
{
}

const char * IMixerOperation::getMappedInputName() const
{
  return m_mappedInputName;
}

cevalue_t IMixerOperation::getInputValue() const
{
  IInput * in = InputManager::Instance().getInput(m_mappedInputName);
  if (in == NULL)
    return US_CENTRE;

  return in->value();
}

cevalue_t IMixerOperation::evaluate(cevalue_t lastValue) const
{
  cevalue_t evaluated = doEvaluation(lastValue);

  // Clamp to range
  if (evaluated < CE_LOW)
    evaluated = CE_LOW;
  else if (evaluated > CE_HIGH)
    evaluated = CE_HIGH;

  return evaluated;
}

cevalue_t IMixerOperation::getWeight() const
{
  return m_weight;
}
