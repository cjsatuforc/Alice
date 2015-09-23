#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGEGENERALSETT
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGEGENERALSETT

#include "IAliceNextionUIPage.h"
#include <NextionPicture.h>

class PageGeneralSett: public IAliceNextionUIPage, public INextionCallback
{
public:
  PageGeneralSett(AliceNextionUI *ui);

  void update();
  void handleNextionEvent(NextionEventType type, INextionTouchable *widget);
  
protected:
  void enterPage();

private:
  AliceNextionUI *m_ui;
  NextionPage *m_page;
  
  NextionPicture *m_pBack;
};

#endif