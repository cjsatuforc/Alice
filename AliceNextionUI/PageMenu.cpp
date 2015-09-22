#include "PageMenu.h"

PageMenu::PageMenu(AliceNextionUI *ui):
  IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_MENU, 0, "pgMenu")),
  INextionCallback(),
  m_pHome(new NextionPicture(ui->nextion(), PG_MENU, 9, "pHome")),
  m_pSplash(new NextionPicture(ui->nextion(), PG_MENU, 10, "pSplash"))
{
  m_pHome->attachCallback(this);
  m_pSplash->attachCallback(this);
}

void PageMenu::update()
{
  // Nothing to do
}

void PageMenu::handleNextionEvent(NextionEventType type, INextionTouchable *widget)
{
  if (type == NEX_EVENT_PUSH)
    return;
  
  if (widget == m_pHome)
    IAliceNextionUIPage::m_ui->showPage(PG_MAIN);
  else if (widget == m_pSplash)
    IAliceNextionUIPage::m_ui->showPage(PG_SPLASH);
}