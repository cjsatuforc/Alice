#include "IMixerOperation.h"

#include "InputManager.h"
#include "IInput.h"

IMixerOperation::IMixerOperation(char * name, char * mappedInputName)
  : AliceObject(name)
  , m_mappedInputName(mappedInputName)
{
}

IMixerOperation::~IMixerOperation()
{
}

char * IMixerOperation::getMappedInputName()
{
  return m_mappedInputName;
}

usvalue_t IMixerOperation::getInputValue()
{
  IInput * in = InputManager::Instance().getInput(m_mappedInputName);
  if (in == NULL)
    return US_CENTRE;

  return in->value();
}
