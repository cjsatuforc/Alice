#include "UIManager.h"

#include "SerialLog.h"
#include "utility/m2ghu8g.h"


// Home Screen
M2_LABEL(label_homeScreen, "", "Home Screen");
M2_ALIGN(align_homeScreen, "-1|1W64H64", &label_homeScreen);


// Channel Menu
IChannel * g_channels;
uint8_t g_channelMenuFirst = 0;
uint8_t g_channelCount = 0;

M2_STRLIST(strlist_channelMenu, "l4W56", &g_channelMenuFirst, &g_channelCount, ui_processChannelMenu);
M2_SPACE(space_channelMenuSpace, "W1h1");
M2_VSB(vsb_channelMenuScrollBar, "l4W2r1", &g_channelMenuFirst, &g_channelCount);
M2_LIST(list_channelMenu) = {&strlist_channelMenu, &space_channelMenuSpace, &vsb_channelMenuScrollBar};
M2_HLIST(hlist_channelMenu, NULL, list_channelMenu);
M2_ALIGN(align_channelMenu, "-1|1W64H64", &hlist_channelMenu);


// Macro Menu
M2_LABEL(label_macroMenu, "", "Macros");
M2_ALIGN(align_macroMenu, "-1|1W64H64", &label_macroMenu);


// Main Menu
m2_xmenu_entry g_mainMenuData[] = {
  {"Channels", &align_channelMenu, NULL},
  {"Macros", &align_macroMenu, NULL},
  {"Setup", NULL, NULL},
  {". Option 1", NULL, NULL},
  {". Option 2", NULL, NULL},
  {NULL, NULL, NULL}
};

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


void ui_init(U8GLIB * glcd, IChannel * channels, uint8_t numChannels)
{
  g_glcd = glcd;
  g_channels = channels;
  g_channelCount = numChannels;
  
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


void ui_handleButtonPress(uibutton_t id)
{
  debug("Button press");
  g_m2tk.setKey(id);
}


const char * ui_processChannelMenu(uint8_t idx, uint8_t msg)
{
  if(idx >= g_channelCount)
    return "";
  
  const char * res = g_channels[idx].getName();
  
  if(msg == M2_STRLIST_MSG_SELECT)
  {
    // Process selection
  }
  
  return res;
}
