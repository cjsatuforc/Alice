#include "InputManager.h"

#include <IButton.h>

#include "ControlMappingManager.h"


void handle_control(inputtype_t type, IInputDevice * device)
{
  ControlMappingManager::Instance().handleInput(type, device);
}


InputManager::InputManager()
{
  m_controls.setCallback(handle_control);
}


bool InputManager::poll(bool controlsOnly)
{
  bool updated = false;

  if(m_controls.poll())
    updated = true;

  // Must ignore any other checks if controlsOnly is true

  return updated;
}


bool InputManager::addControl(IInputDevice * device)
{
  return m_controls.addDevice(device);
}
