#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGESPLASH
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGESPLASH

#include "IAliceNextionUIPage.h"
#include <NextionHotspot.h>

class PageSplash: public IAliceNextionUIPage, public INextionCallback
{
public:
  PageSplash(AliceNextionUI *ui);

  void update();
  void handleNextionEvent(NextionEventType type, INextionTouchable *widget);

private:
  AliceNextionUI *m_ui;
  NextionPage *m_page;
  
  NextionHotspot *m_mContinue;
};

#endif