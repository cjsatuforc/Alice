#include "PageChanOpt.h"

PageChanOpt::PageChanOpt(AliceNextionUI *ui)
    : IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_CHANOPT, 0, "pgChanOpt"))
    , INextionCallback()
    , m_pBack(new NextionPicture(ui->nextion(), PG_CHANOPT, 1, "pBack"))
    , m_tCName(new NextionText(ui->nextion(), PG_CHANOPT, 2, "tCName"))
    , m_tCNum(new NextionText(ui->nextion(), PG_CHANOPT, 3, "tCNum"))
    , m_tCVal(new NextionText(ui->nextion(), PG_CHANOPT, 8, "tCVal"))
    , m_btCRev(new NextionDualStateButton(ui->nextion(), PG_CHANOPT, 22, "btCRev"))
    , m_hCVal(new NextionSlider(ui->nextion(), PG_CHANOPT, 4, "hCVal"))
    , m_tCMinVal(new NextionText(ui->nextion(), PG_CHANOPT, 16, "tCMinVal"))
    , m_pCMinUp(new NextionPicture(ui->nextion(), PG_CHANOPT, 13, "pCMinUp"))
    , m_pCMinDown(new NextionPicture(ui->nextion(), PG_CHANOPT, 10, "pCMinDown"))
    , m_tCCentVal(new NextionText(ui->nextion(), PG_CHANOPT, 17, "tCCentVal"))
    , m_pCCentUp(new NextionPicture(ui->nextion(), PG_CHANOPT, 14, "pCCentUp"))
    , m_pCCentDown(new NextionPicture(ui->nextion(), PG_CHANOPT, 11, "pCCentDown"))
    , m_tCMaxVal(new NextionText(ui->nextion(), PG_CHANOPT, 18, "tCMaxVal"))
    , m_pCMaxUp(new NextionPicture(ui->nextion(), PG_CHANOPT, 15, "pCMaxUp"))
    , m_pCMaxDown(new NextionPicture(ui->nextion(), PG_CHANOPT, 12, "pCMaxDown"))
    , m_tCTrimVal(new NextionText(ui->nextion(), PG_CHANOPT, 9, "tCTrimVal"))
    , m_pCTrimUp(new NextionPicture(ui->nextion(), PG_CHANOPT, 5, "pCTrimUp"))
    , m_pCTrimDown(new NextionPicture(ui->nextion(), PG_CHANOPT, 6, "pCTrimDown"))
{
  m_pBack->attachCallback(this);
  m_btCRev->attachCallback(this);
  m_hCVal->attachCallback(this);
  m_pCMinUp->attachCallback(this);
  m_pCMinDown->attachCallback(this);
  m_pCCentUp->attachCallback(this);
  m_pCCentDown->attachCallback(this);
  m_pCMaxUp->attachCallback(this);
  m_pCMaxDown->attachCallback(this);
  m_pCTrimUp->attachCallback(this);
  m_pCTrimDown->attachCallback(this);
}

void PageChanOpt::update()
{
  // Nothing to do
}

void PageChanOpt::handleNextionEvent(NextionEventType type, INextionTouchable *widget)
{
  if (type == NEX_EVENT_PUSH)
    return;

  if (widget == m_pBack)
    IAliceNextionUIPage::m_ui->showPage(PG_CHANSEL);
  
  else if (widget == m_hCVal)
  {
    Serial.println("slider moved");
  }
  else if (widget == m_btCRev)
  {
    Serial.println("reverse pressed");
  }
  else if (widget == m_pCMinUp)
  {
    Serial.println("min +");
  }
  else if (widget == m_pCMinDown)
  {
    Serial.println("min -");
  }
  else if (widget == m_pCCentUp)
  {
    Serial.println("cent +");
  }
  else if (widget == m_pCCentDown)
  {
    Serial.println("cent -");
  }
  else if (widget == m_pCMaxUp)
  {
    Serial.println("max +");
  }
  else if (widget == m_pCMaxDown)
  {
    Serial.println("max -");
  }
  else if (widget == m_pCTrimUp)
  {
    Serial.println("trim +");
  }
  else if (widget == m_pCTrimDown)
  {
    Serial.println("trim -");
  }
}

void PageChanOpt::enterPage()
{
  m_tCName->setText("text channel");
  m_tCNum->setTextAsNumber(32);
  m_tCVal->setTextAsNumber(1500);
  m_tCMinVal->setTextAsNumber(1);
  m_tCCentVal->setTextAsNumber(2);
  m_tCMaxVal->setTextAsNumber(3);
  m_tCTrimVal->setTextAsNumber(-4);
}
