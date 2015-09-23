#include "PageGeneralSett.h"

PageGeneralSett::PageGeneralSett(AliceNextionUI *ui):
  IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_GENERALSETT, 0, "pgGeneralSett")),
  INextionCallback(),
  m_pBack(new NextionPicture(ui->nextion(), PG_GENERALSETT, 1, "pBack"))
{
  m_pBack->attachCallback(this);
}

void PageGeneralSett::update()
{
  // Nothing to do
}

void PageGeneralSett::handleNextionEvent(NextionEventType type, INextionTouchable *widget)
{
  if (type == NEX_EVENT_PUSH)
    return;

  if (widget == m_pBack)
    IAliceNextionUIPage::m_ui->showPage(PG_MENU);
}

void PageGeneralSett::enterPage()
{
  // Nothing to do
}