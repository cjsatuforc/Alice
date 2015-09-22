#ifndef __ALICENEXTIONUI_IALICENEXTIONUIPAGE
#define __ALICENEXTIONUI_IALICENEXTIONUIPAGE

#include "AliceNextionUI.h"
#include <NextionPage.h>

class IAliceNextionUIPage
{
public:
  IAliceNextionUIPage(AliceNextionUI *ui, NextionPage *page);
  
  uint8_t id();

  virtual void update() = 0;
  
  bool isShown();
  bool show();

protected:
  AliceNextionUI *m_ui;
  NextionPage *m_page;
};

#endif