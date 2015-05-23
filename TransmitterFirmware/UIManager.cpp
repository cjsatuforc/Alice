#include "UIManager.h"

#include "SerialLog.h"
#include "ChannelManager.h"

#include <utility/m2ghu8g.h>

// Home Screen
M2_LABEL(label_homeScreen, "", "Home Screen");
M2_ALIGN(align_homeScreen, "-1|1W64H64", &label_homeScreen);

// Main Menu
m2_xmenu_entry g_mainMenuData[ALICE_MAX_MAIN_MENU_ELEMENTS];

uint8_t g_mainMenuFirst = 0;
uint8_t g_mainMenuCount = 3;

M2_X2LMENU(menu_mainMenu, "l4W56", &g_mainMenuFirst, &g_mainMenuCount, g_mainMenuData, 65, 102, '\0');
M2_SPACE(space_menuSpace, "W1h1");
M2_VSB(vsb_menuScrollBar, "l4W2r1", &g_mainMenuFirst, &g_mainMenuCount);
M2_LIST(list_mainMenu) = {&menu_mainMenu, &space_menuSpace, &vsb_menuScrollBar};
M2_HLIST(hlist_mainMenu, NULL, list_mainMenu);
M2_ALIGN(align_mainMenu, "-1|1W64H64", &hlist_mainMenu);


M2tk g_m2tk(&align_homeScreen, m2_es_arduino, m2_eh_6bs, m2_gh_u8g_fb);
U8GLIB * g_glcd;


void ui_init(U8GLIB * glcd)
{
  // Create menu structure
  int i = 0;
  g_mainMenuData[i++] = (m2_xmenu_entry) {"Channels", NULL, NULL};

  for(int j = 0; j < ChannelManager::Instance().numChannels(); j++)
  {
    Channel * channel = ChannelManager::Instance().getChannel(j);
    char * name = new char[3 + strlen(channel->getName())];
    sprintf(name, ". %s\0", channel->getName());
    g_mainMenuData[i++] = (m2_xmenu_entry) {name, NULL, NULL};
  }

  g_mainMenuData[i++] = (m2_xmenu_entry) {"Macros", NULL, NULL};

  g_mainMenuData[i++] = (m2_xmenu_entry) {"Setup", NULL, NULL};
  g_mainMenuData[i++] = (m2_xmenu_entry) {". Radio Tx Period", NULL, NULL};
  g_mainMenuData[i++] = (m2_xmenu_entry) {". UI Frame Rate", NULL, NULL};

  g_mainMenuData[i++] = (m2_xmenu_entry) {NULL, NULL, NULL};


  g_glcd = glcd;

  // Connect u8glib with m2tklib
  m2_SetU8g(glcd->getU8g(), m2_u8g_box_icon);

  // Set home screens
  g_m2tk.setHome(&align_homeScreen);
  g_m2tk.setHome2(&align_mainMenu);

  // Assign u8g font to index 0
  g_m2tk.setFont(0, u8g_font_6x13r);
}


void ui_update()
{
  if(g_m2tk.handleKey() != 0)
  {
    g_glcd->firstPage();
    do
    {
      g_m2tk.draw();
    } while(g_glcd->nextPage());
  }
}


void ui_handleButton(inputtype_t type, IInputDevice * device)
{
  if(type == UIT_BUTTON)
  {
    IButton * button = (IButton *) device;
    if(button->isActive())
    {
      debug("Button press");
      g_m2tk.setKey(button->getID());
    }
  }
}


const char * ui_processChannelMenu(uint8_t idx, uint8_t msg)
{
  Channel * channel = ChannelManager::Instance().getChannel(idx);

  if(channel == NULL)
    return "";

  const char * res = channel->getName();

  if(msg == M2_STRLIST_MSG_SELECT)
  {
    // Process selection
  }

  return res;
}
