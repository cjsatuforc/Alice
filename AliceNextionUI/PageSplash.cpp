#include "PageSplash.h"

PageSplash::PageSplash(AliceNextionUI *ui):
  IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_SPLASH, 0, "pgSplash")),
  INextionCallback(),
  m_mContinue(new NextionHotspot(ui->nextion(), PG_SPLASH, 5, "mContinue"))
{
  m_mContinue->attachCallback(this);
}

void PageSplash::update()
{
  // Nothing to do
}

void PageSplash::handleNextionEvent(NextionEventType type, INextionTouchable *widget)
{
  if (type == NEX_EVENT_PUSH)
    return;

  IAliceNextionUIPage::m_ui->showPage(PG_MAIN);
}

void PageSplash::enterPage()
{
  // Nothing to do
}