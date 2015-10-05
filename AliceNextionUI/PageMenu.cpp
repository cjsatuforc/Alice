#include "PageMenu.h"

PageMenu::PageMenu(AliceNextionUI *ui)
    : IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_MENU, 0, "pgMenu"))
    , INextionCallback()
    , m_pHome(new NextionPicture(ui->nextion(), PG_MENU, 9, "pHome"))
    , m_pSplash(new NextionPicture(ui->nextion(), PG_MENU, 10, "pSplash"))
    , m_bTrim(new NextionButton(ui->nextion(), PG_MENU, 1, "bTrim"))
    , m_bChannel(new NextionButton(ui->nextion(), PG_MENU, 2, "bChannel"))
    , m_bGeneral(new NextionButton(ui->nextion(), PG_MENU, 3, "bGeneral"))
{
  m_pHome->attachCallback(this);
  m_pSplash->attachCallback(this);

  m_bTrim->attachCallback(this);
  m_bChannel->attachCallback(this);
  m_bGeneral->attachCallback(this);
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
  else if (widget == m_bTrim)
    IAliceNextionUIPage::m_ui->showPage(PG_TRIM);
  else if (widget == m_bChannel)
    IAliceNextionUIPage::m_ui->showPage(PG_CHANSEL);
  else if (widget == m_bGeneral)
    IAliceNextionUIPage::m_ui->showPage(PG_GENERALSETT);
}

void PageMenu::enterPage()
{
  // Nothing to do

  //TODO: dev only

  size_t len = 6;
  char buffer[len];
  Serial.println(m_bChannel->getText(buffer, len));
  Serial.println(buffer);

  len = 15;
  char buffer2[len];
  Serial.println(m_bChannel->getText(buffer2, len));
  Serial.println(buffer2);
}
