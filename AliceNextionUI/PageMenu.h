#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGEMENU
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGEMENU

#include "IAliceNextionUIPage.h"
#include <NextionPicture.h>
#include <NextionButton.h>

class PageMenu : public IAliceNextionUIPage, public INextionCallback
{
public:
  PageMenu(AliceNextionUI *ui);

  void update();
  void handleNextionEvent(NextionEventType type, INextionTouchable *widget);

protected:
  void enterPage();

private:
  AliceNextionUI *m_ui;
  NextionPage *m_page;

  NextionPicture *m_pHome;
  NextionPicture *m_pSplash;

  NextionButton *m_bTrim;
  NextionButton *m_bChannel;
  NextionButton *m_bGeneral;
};

#endif
