#ifndef ALICE_UIMANAGER_H
#define ALICE_UIMANAGER_H

#include "Types.h"

#include <U8glib.h>
#include <M2tk.h>

class UIManager
{
  public:
    UIManager(U8GLIB & glcd);
    ~UIManager();

    void update();
    void handleButtonPress(uibutton_t id);

  private:
    U8GLIB & m_glcd;
    M2tk m_m2;

};

#endif
