#include "PageChanSel.h"

PageChanSel::PageChanSel(AliceNextionUI *ui):
  IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_CHANSEL, 0, "pgChanSel")),
  INextionCallback(),
  m_pBack(new NextionPicture(ui->nextion(), PG_CHANSEL, 0, "pBack"))
{
  m_pBack->attachCallback(this);
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
}

void PageChanSel::enterPage()
{
  // Nothing to do
}