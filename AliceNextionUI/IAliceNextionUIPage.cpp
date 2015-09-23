#include "IAliceNextionUIPage.h"

IAliceNextionUIPage::IAliceNextionUIPage(AliceNextionUI *ui, NextionPage *page)
    : m_ui(ui)
    , m_page(page)
{
}

uint8_t IAliceNextionUIPage::id() { return m_page->getPageID(); }

bool IAliceNextionUIPage::isShown()
{
  return m_ui->nextion().getCurrentPage() == m_page->getPageID();
}

bool IAliceNextionUIPage::show()
{
  bool result = m_page->show();
  enterPage();
  return result;
}
