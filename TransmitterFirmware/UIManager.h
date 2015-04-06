#ifndef ALICE_UIMANAGER_H
#define ALICE_UIMANAGER_H

#include "Types.h"
#include <U8glib.h>

class UIManager
{
  public:
    UIManager(U8GLIB & glcd);
    ~UIManager();

    void handleButtonPress(uibutton_t id);

  private:
    const U8GLIB & m_glcd;

};

#endif
