#include "PageChanSel.h"

PageChanSel::PageChanSel(AliceNextionUI *ui)
    : IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_CHANSEL, 0, "pgChanSel"))
    , INextionCallback()
    , m_pBack(new NextionPicture(ui->nextion(), PG_CHANSEL, 1, "pBack"))
    , m_pCSelect(new NextionPicture(ui->nextion(), PG_CHANSEL, 2, "pCSelect"))
    , m_pCNext(new NextionPicture(ui->nextion(), PG_CHANSEL, 4, "pCNext"))
    , m_pCPrev(new NextionPicture(ui->nextion(), PG_CHANSEL, 3, "pCPrev"))
    , m_tCName(new NextionText(ui->nextion(), PG_CHANSEL, 5, "tCName"))
    , m_tCNum(new NextionText(ui->nextion(), PG_CHANSEL, 6, "tCNum"))
{
  m_pBack->attachCallback(this);
  m_pCSelect->attachCallback(this);
  m_pCNext->attachCallback(this);
  m_pCPrev->attachCallback(this);
}

void PageChanSel::update()
{
  // Nothing to do
}

void PageChanSel::handleNextionEvent(NextionEventType type, INextionTouchable *widget)
{
  if (type == NEX_EVENT_PUSH)
    return;

  if (widget == m_pBack)
    IAliceNextionUIPage::m_ui->showPage(PG_MENU);
  
  else if (widget == m_pCNext)
  {
    Serial.println("next channel");
  }
  else if (widget == m_pCPrev)
  {
    Serial.println("prev channel");
  }
  else if (widget == m_pCSelect)
  {
    Serial.println("channel selected");
    IAliceNextionUIPage::m_ui->showPage(PG_CHANOPT);
  }
}

void PageChanSel::enterPage()
{
  m_tCName->setText("channel 1");
  m_tCNum->setTextAsNumber(32);
}
