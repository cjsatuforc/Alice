#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGESMAIN
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGESMAIN

#include "IAliceNextionUIPage.h"
#include <NextionPicture.h>

class PageMain: public IAliceNextionUIPage, public INextionCallback
{
public:
  PageMain(AliceNextionUI *ui);

  void update();
  void handleNextionEvent(NextionEventType type, INextionTouchable *widget);

private:
  AliceNextionUI *m_ui;
  NextionPage *m_page;
  
  NextionPicture *m_pMenu;
};

#endif