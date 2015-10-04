#include "PageMain.h"

PageMain::PageMain(AliceNextionUI *ui)
    : IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_MAIN, 0, "pgMain"))
    , INextionCallback()
    , m_pMenu(new NextionPicture(ui->nextion(), PG_MAIN, 5, "pMenu"))
{
  m_pMenu->attachCallback(this);
}

void PageMain::update()
{
}

void PageMain::handleNextionEvent(NextionEventType type, INextionTouchable *widget)
{
  if (type == NEX_EVENT_PUSH)
    return;

  if (widget == m_pMenu)
    IAliceNextionUIPage::m_ui->showPage(PG_MENU);
}

void PageMain::enterPage()
{
  // Nothing to do
}
