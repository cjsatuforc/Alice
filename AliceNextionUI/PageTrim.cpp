#include "PageTrim.h"

// TODO
PageTrim::PageTrim(AliceNextionUI *ui)
    : IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_TRIM, 0, "pgTrim"))
    , INextionCallback()
    , m_pBack(new NextionPicture(ui->nextion(), PG_TRIM, 9, "pBack"))
    , m_pLeftHUp(new NextionPicture(ui->nextion(), PG_TRIM, 16, "pLeftHUp"))
    , m_pLeftHDown(new NextionPicture(ui->nextion(), PG_TRIM, 14, "pLeftHDown"))
    , m_pLeftVUp(new NextionPicture(ui->nextion(), PG_TRIM, 17, "pLeftVUp"))
    , m_pLeftVDown(new NextionPicture(ui->nextion(), PG_TRIM, 15, "pLeftVDown"))
    , m_pRightHUp(new NextionPicture(ui->nextion(), PG_TRIM, 10, "pRightUp"))
    , m_pRightHDown(new NextionPicture(ui->nextion(), PG_TRIM, 11, "pRightHDown"))
    , m_pRightVUp(new NextionPicture(ui->nextion(), PG_TRIM, 13, "pRightVUp"))
    , m_pRightVDown(new NextionPicture(ui->nextion(), PG_TRIM, 12, "pRightVDown"))
    , m_tLeftHVal(new NextionText(ui->nextion(), PG_TRIM, 0, "m_tLeftHVal"))
    , m_tLeftVVal(new NextionText(ui->nextion(), PG_TRIM, 0, "m_tLeftVVal"))
    , m_tRightHVal(new NextionText(ui->nextion(), PG_TRIM, 0, "m_tRightHVal"))
    , m_tRightVVal(new NextionText(ui->nextion(), PG_TRIM, 0, "m_tRightVVal"))
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
}

void PageTrim::enterPage()
{
  // Nothing to do
}
