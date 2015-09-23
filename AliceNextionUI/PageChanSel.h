#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGECHANSEL
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGECHANSEL

#include "IAliceNextionUIPage.h"
#include <NextionPicture.h>

class PageChanSel : public IAliceNextionUIPage, public INextionCallback
{
public:
  PageChanSel(AliceNextionUI *ui);

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
