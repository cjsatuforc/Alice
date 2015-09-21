#include "AliceNextionUI.h"
#include "IAliceNextionUIPage.h"

AliceNextionUI::AliceNextionUI(Nextion &nex):
  m_nextion(nex)
{
  memset(m_pages, PG_NULL, NULL);
}

bool AliceNextionUI::addPage(IAliceNextionUIPage *page)
{
  if(page->id() >= PG_NULL)
    return false;

  if(m_pages[page->id()] != NULL)
    return false;

  m_pages[page->id()] = page;
  return false;
}

bool AliceNextionUI::showPage(AliceNextionUIPageID id)
{
  if(m_pages[id] == NULL)
    return false;

  return m_pages[id]->show();
}

void AliceNextionUI::update()
{
  m_pages[m_nextion.getCurrentPage()]->update();
}

void AliceNextionUI::poll()
{
  m_nextion.poll();
}

Nextion &AliceNextionUI::nextion()
{
  return m_nextion;
}