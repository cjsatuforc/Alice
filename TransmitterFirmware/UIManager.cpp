#include "UIManager.h"

#include "SerialLog.h"


UIManager::UIManager(U8GLIB & glcd) :
  m_glcd(glcd)
{
}


UIManager::~UIManager()
{
}


void UIManager::handleButtonPress(uibutton_t id)
{
  debug("Button press");
}
