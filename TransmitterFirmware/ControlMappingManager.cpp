#include "ControlMappingManager.h"

#include <IButton.h>
#include <IJoystick.h>

#include "InputManager.h"
#include "ChannelManager.h"


ControlMappingManager::ControlMappingManager()
{
  for(int i = 0; i < MAX_MAPPINGS; i++)
    m_mappings[i] = NULL;
}


bool ControlMappingManager::handleInput(inputtype_t type, IInputDevice * device)
{
  for(int i = 0; i < m_numMappings; i++)
  {
    switch(type)
    {
      case UIT_JOYSTICK:
      {
        ControlMapping * mapping = m_mappings[i];
        if((mapping->getMode() == CONTROLMODE_SET) &&
            mapping->getInputID() == device->getID())
        {
          IJoystick * joystick = (IJoystick *) device;
          ChannelManager::Instance().getChannel(mapping->getChannelID())->setValue(joystick->getValue());
        }
        break;
      }
      case UIT_BUTTON:
      {
        //TODO
        break;
      }
    }
  }
}


bool ControlMappingManager::addMapping(ControlMapping * mapping)
{
  if(mapping == NULL)
    return false;

  if(m_numMappings == MAX_MAPPINGS)
    return false;

  m_mappings[m_numMappings] = mapping;
  m_numMappings++;
  return true;
}
