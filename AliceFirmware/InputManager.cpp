/** @file */

#include "InputManager.h"

InputManager::InputManager()
{
  for (size_t i = 0; i < MAX_NUM_INPUTS; i++)
    m_inputs[i] = NULL;
}

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

IInput * InputManager::getInput(const char * inputName)
{
  for (size_t i = 0; i < MAX_NUM_INPUTS; i++)
  {
    if (m_inputs[i] != NULL && strcmp(m_inputs[i]->getName(), inputName) == 0)
      return m_inputs[i];
  }

  return NULL;
}
