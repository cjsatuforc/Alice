#include "PageChanOpt.h"

PageChanOpt::PageChanOpt(AliceNextionUI *ui)
    : IAliceNextionUIPage(ui, new NextionPage(ui->nextion(), PG_CHANOPT, 0, "pgMenu"))
    , INextionCallback()
    , m_pBack(new NextionPicture(ui->nextion(), PG_CHANOPT, 1, "pBack"))
{
  m_pBack->attachCallback(this);
}

void PageChanOpt::update()
{
  // Nothing to do
}

void PageChanOpt::handleNextionEvent(NextionEventType type, INextionTouchable *widget) {}

void PageChanOpt::enterPage()
{
  // Nothing to do
}
