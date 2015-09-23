#include "PageTrim.h"

PageTrim::PageTrim(AliceNextionUI *ui)
    : IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_TRIM, 0, "pgTrim"))
    , INextionCallback()
    , m_pBack(new NextionPicture(ui->nextion(), PG_TRIM, 9, "pBack"))
    , m_pLeftHUp(new NextionPicture(ui->nextion(), PG_TRIM, 16, "pLeftHUp"))
    , m_pLeftHDown(new NextionPicture(ui->nextion(), PG_TRIM, 14, "pLeftHDown"))
    , m_pLeftVUp(new NextionPicture(ui->nextion(), PG_TRIM, 17, "pLeftVUp"))
    , m_pLeftVDown(new NextionPicture(ui->nextion(), PG_TRIM, 15, "pLeftVDown"))
    , m_pRightHUp(new NextionPicture(ui->nextion(), PG_TRIM, 13, "pRightHUp"))
    , m_pRightHDown(new NextionPicture(ui->nextion(), PG_TRIM, 12, "pRightHDown"))
    , m_pRightVUp(new NextionPicture(ui->nextion(), PG_TRIM, 10, "pRightVUp"))
    , m_pRightVDown(new NextionPicture(ui->nextion(), PG_TRIM, 11, "pRightVDown"))
    , m_tLeftHVal(new NextionText(ui->nextion(), PG_TRIM, 8, "tLeftHVal"))
    , m_tLeftVVal(new NextionText(ui->nextion(), PG_TRIM, 7, "tLeftVVal"))
    , m_tRightHVal(new NextionText(ui->nextion(), PG_TRIM, 5, "tRightHVal"))
    , m_tRightVVal(new NextionText(ui->nextion(), PG_TRIM, 6, "tRightVVal"))
{
  m_pBack->attachCallback(this);

  m_pLeftHUp->attachCallback(this);
  m_pLeftHDown->attachCallback(this);
  m_pLeftVUp->attachCallback(this);
  m_pLeftVDown->attachCallback(this);
  m_pRightHUp->attachCallback(this);
  m_pRightHDown->attachCallback(this);
  m_pRightVUp->attachCallback(this);
  m_pRightVDown->attachCallback(this);
}

void PageTrim::update()
{
  // Nothing to do
}

void PageTrim::handleNextionEvent(NextionEventType type, INextionTouchable *widget)
{
  if (type == NEX_EVENT_PUSH)
    return;

  if (widget == m_pBack)
    IAliceNextionUIPage::m_ui->showPage(PG_MENU);
  
  else if (widget == m_pLeftHUp)
  {
    Serial.println("left h up");
  }
  else if (widget == m_pLeftHDown)
  {
    Serial.println("left h down");
  }
  else if (widget == m_pLeftVUp)
  {
    Serial.println("left v up");
  }
  else if (widget == m_pLeftVDown)
  {
    Serial.println("left v down");
  }
  else if (widget == m_pRightHUp)
  {
    Serial.println("right h up");
  }
  else if (widget == m_pRightHDown)
  {
    Serial.println("right h down");
  }
  else if (widget == m_pRightVUp)
  {
    Serial.println("right v up");
  }
  else if (widget == m_pRightVDown)
  {
    Serial.println("right v down");
  }
}

void PageTrim::enterPage()
{
  m_tLeftHVal->setTextAsNumber(0);
  m_tLeftVVal->setTextAsNumber(1);
  m_tRightHVal->setTextAsNumber(2);
  m_tRightVVal->setTextAsNumber(3);
}
