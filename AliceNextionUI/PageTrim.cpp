#include "PageTrim.h"

PageTrim::PageTrim(AliceNextionUI *ui):
  IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_TRIM, 0, "pgTrim")),
  INextionCallback(),
  m_pBack(new NextionPicture(ui->nextion(), PG_TRIM, 9, "pBack")),
  m_pLeftHUp(new NextionPicture(ui->nextion(), PG_TRIM, 16, "pLeftHUp")),
  m_pLeftHDown(new NextionPicture(ui->nextion(), PG_TRIM, 14, "pLeftHDown")),
  m_pLeftVUp(new NextionPicture(ui->nextion(), PG_TRIM, 17, "pLeftVUp")),
  m_pLeftVDown(new NextionPicture(ui->nextion(), PG_TRIM, 15, "pLeftVDown")),
  m_pRightHUp(new NextionPicture(ui->nextion(), PG_TRIM, 10, "pRightUp")),
  m_pRightHDown(new NextionPicture(ui->nextion(), PG_TRIM, 11, "pRightHDown")),
  m_pRightVUp(new NextionPicture(ui->nextion(), PG_TRIM, 13, "pRightVUp")),
  m_pRightVDown(new NextionPicture(ui->nextion(), PG_TRIM, 12, "pRightVDown"))
{
  m_pBack->attachCallback(this);
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