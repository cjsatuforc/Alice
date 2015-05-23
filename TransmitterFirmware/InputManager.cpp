#include "InputManager.h"

#include <IButton.h>

#include "UIManager.h"


InputManager::InputManager()
{
  m_uiButtons.setCallback(ui_handleButton);
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
