#include "UIManager.h"

#include "SerialLog.h"
#include "utility/m2ghu8g.h"


// Main menu
m2_xmenu_entry mainMenuData[] =
{
  { "Channels", NULL, NULL },
  { "Macros", NULL, NULL },
  { "Setup", NULL, NULL },
  { NULL, NULL, NULL },
};

uint8_t mainMenuFirst = 0;
uint8_t mainMenuCount = 3;

M2_X2LMENU(menu_mainMenu, "l4W52", &mainMenuFirst, &mainMenuCount, mainMenuData, 65, 102, '\0');
M2_SPACE(space_menuSpace, "W1h1");
M2_VSB(vsb_menuScrollBar, "l4W2r1", &mainMenuFirst, &mainMenuCount);
M2_LIST(list_mainMenu) = { &menu_mainMenu, &space_menuSpace, &vsb_menuScrollBar };
M2_HLIST(hlist_mainMenu, NULL, list_mainMenu);
M2_ALIGN(align_mainMenu, "-1|1W64H64", &hlist_mainMenu);


UIManager::UIManager(U8GLIB & glcd) :
  m_glcd(glcd),
  m_m2(&align_mainMenu, m2_es_arduino, m2_eh_4bs, m2_gh_u8g_ffs)
{
  // Connect u8glib with m2tklib
  m2_SetU8g(glcd.getU8g(), m2_u8g_box_icon);

  // Assign u8g font to index 0
  m_m2.setFont(0, u8g_font_6x13r);
}


UIManager::~UIManager()
{
}


void UIManager::update()
{
  if(m_m2.handleKey() != 0)
  {
    m_glcd.firstPage();
    do
    {
      m_m2.draw();
    } while(m_glcd.nextPage());
  }
}


void UIManager::handleButtonPress(uibutton_t id)
{
  debug("Button press");
  m_m2.setKey(id);
}
