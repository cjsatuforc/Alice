#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGEMENU
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGEMENU

#include "IAliceNextionUIPage.h"
#include <NextionPicture.h>

class PageMenu: public IAliceNextionUIPage, public INextionCallback
{
public:
  PageMenu(AliceNextionUI *ui);

  void update();
  void handleNextionEvent(NextionEventType type, INextionTouchable *widget);

private:
  AliceNextionUI *m_ui;
  NextionPage *m_page;
  
  NextionPicture *m_pHome;
  NextionPicture *m_pSplash;
};

#endif