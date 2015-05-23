#include "InputManager.h"

#include <IButton.h>

#include "UIManager.h"
#include "ControlMappingManager.h"


void handleControl(inputtype_t type, IInputDevice * device)
{
  ControlMappingManager::Instance().handleInput(type, device);
}


InputManager::InputManager()
{
  m_uiButtons.setCallback(ui_handleButton);
  m_controls.setCallback(handleControl);
}


bool InputManager::poll(bool ui, bool controls)
{
  bool updated = false;

  if(ui && m_uiButtons.poll())
    updated = true;

  if(controls && m_controls.poll())
    updated = true;

  return updated;
}


bool InputManager::addUIButton(uibutton_t id, inputpin_t pin)
{
  return m_uiButtons.addNewButton(id, pin);
}


bool InputManager::addControl(IInputDevice * device)
{
  return m_controls.addDevice(device);
}
