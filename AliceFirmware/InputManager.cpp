/*! \file */

#include "InputManager.h"

InputManager::InputManager()
{
  for (size_t i = 0; i < MAX_NUM_INPUTS; i++)
    m_inputs[i] = NULL;
}

IInput * InputManager::getInput(char * inputName)
{
  // TODO
  return NULL;
}
