/** @file */

#include "InputManager.h"

/**
 * @brief Constructs the InputManager.
 */
InputManager::InputManager()
    : m_inputs(MAX_NUM_INPUTS)
{
}

/**
 * @copydoc AliceObjectList::add
 */
bool InputManager::addInput(IInput *item)
{
  return m_inputs.add(item);
}

/**
 * @copydoc AliceObjectList::getByName
 */
IInput *InputManager::getInput(const char *name)
{
  return (IInput *)m_inputs.getByName(name);
}

/**
 * @brief Polls input devices for changes.
 */
void InputManager::poll()
{
  // TODO
}
