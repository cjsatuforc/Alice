/** @file */

#include "IInput.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param type Input device type
 */
IInput::IInput(char *name, InputType type)
    : AliceObject(name)
    , m_type(type)
{
}

IInput::~IInput()
{
}

/**
 * @brief Gets the type of the input device.
 * @return Device type
 */
InputType IInput::type() const
{
  return m_type;
}
