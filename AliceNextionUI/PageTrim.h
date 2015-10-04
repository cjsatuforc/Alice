#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGETRIM
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGETRIM

#include "IAliceNextionUIPage.h"
#include <NextionPicture.h>
#include <NextionText.h>

class PageTrim : public IAliceNextionUIPage, public INextionCallback
{
public:
  static const uint8_t TRIM_DELTA = 5;
  static const uint8_t CHAN_HORIZ_LEFT = 3;
  static const uint8_t CHAN_VERT_LEFT = 2;
  static const uint8_t CHAN_HORIZ_RIGHT = 0;
  static const uint8_t CHAN_VERT_RIGHT = 1;

  PageTrim(AliceNextionUI *ui);

  void update();
  void handleNextionEvent(NextionEventType type, INextionTouchable *widget);

protected:
  void enterPage();

private:
  AliceNextionUI *m_ui;
  NextionPage *m_page;

  NextionPicture *m_pBack;

  NextionPicture *m_pLeftHUp;
  NextionPicture *m_pLeftHDown;
  NextionPicture *m_pLeftVUp;
  NextionPicture *m_pLeftVDown;

  NextionPicture *m_pRightHUp;
  NextionPicture *m_pRightHDown;
  NextionPicture *m_pRightVUp;
  NextionPicture *m_pRightVDown;

  NextionText *m_tLeftHVal;
  NextionText *m_tLeftVVal;
  NextionText *m_tRightHVal;
  NextionText *m_tRightVVal;
};

#endif
