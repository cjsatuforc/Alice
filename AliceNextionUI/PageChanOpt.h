#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGECHANOPT
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGECHANOPT

#include "IAliceNextionUIPage.h"
#include <NextionPicture.h>

class PageChanOpt : public IAliceNextionUIPage, public INextionCallback
{
public:
  PageChanOpt(AliceNextionUI *ui);

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
