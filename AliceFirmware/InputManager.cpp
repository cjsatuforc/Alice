/** @file */

#include "InputManager.h"

/**
 * @brief Constructs the InputManager.
 */
InputManager::InputManager()
{
  for (size_t i = 0; i < MAX_NUM_INPUTS; i++)
    m_inputs[i] = NULL;
}

/**
 * @brief Adds a new input device to the manager.
 * @param input Pointer to the input device
 * @return True if the device was added, false if the maximum number of devices
 *         have already been added
 */
bool InputManager::addInput(IInput * input)
{
  for (size_t i = 0; i < MAX_NUM_INPUTS; i++)
  {
    if (m_inputs[i] == NULL)
    {
      m_inputs[i] = input;
      return true;
    }
  }

  return false;
}

/**
 * @brief Gets an input device given it's name.
 * @param inputName Name of the input device
 * @return Pointer to the input device, NULL if it does not exist
 */
IInput * InputManager::getInput(const char * inputName)
{
  for (size_t i = 0; i < MAX_NUM_INPUTS; i++)
  {
    if (m_inputs[i] != NULL && strcmp(m_inputs[i]->getName(), inputName) == 0)
      return m_inputs[i];
  }

  return NULL;
}
