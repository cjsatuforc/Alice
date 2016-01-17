#include "IInput.h"

IInput::IInput(char * name, InputType type)
  : AliceObject(name)
  , m_type(type)
{
}

IInput::~IInput()
{
}

InputType IInput::type() const
{
  return m_type;
}
