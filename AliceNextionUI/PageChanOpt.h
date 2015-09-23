#ifndef __ALICENEXTIONUI_ALICENEXTIONUIPAGECHANOPT
#define __ALICENEXTIONUI_ALICENEXTIONUIPAGECHANOPT

#include "IAliceNextionUIPage.h"
#include <NextionPicture.h>
#include <NextionText.h>
#include <NextionDualStateButton.h>
#include <NextionSlider.h>

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
  
  NextionText *m_tCName;
  NextionText *m_tCNum;
  NextionText *m_tCVal;
  
  NextionDualStateButton *m_btCRev;
  
  NextionSlider *m_hCVal;
  
  NextionText *m_tCMinVal;
  NextionPicture *m_pCMinUp;
  NextionPicture *m_pCMinDown;
  
  NextionText *m_tCCentVal;
  NextionPicture *m_pCCentUp;
  NextionPicture *m_pCCentDown;
  
  NextionText *m_tCMaxVal;
  NextionPicture *m_pCMaxUp;
  NextionPicture *m_pCMaxDown;
  
  NextionText *m_tCTrimVal;
  NextionPicture *m_pCTrimUp;
  NextionPicture *m_pCTrimDown;
};

#endif
