#include "PageSplash.h"

PageSplash::PageSplash(AliceNextionUI *ui):
  IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_SPLASH, 0, "pgSplash")),
  INextionCallback(),
  m_mContinue(new NextionHotspot(ui->nextion(), PG_SPLASH, 5, "mContinue"))
{
  Serial.println(m_mContinue->attachReleaseEvent(this));
}

void PageSplash::update()
{
  // Nothing to do
}

void PageSplash::handleNextionEvent(INextionTouchable *item)
{
  Serial.println("event");
}