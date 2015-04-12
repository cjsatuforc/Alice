#include <inttypes.h>

#include <UniversalInput.h>
#include <UniversalButtons.h>
#include <U8glib.h>
#include <M2tk.h>
#include <utility/m2ghu8g.h>

#include "SerialLog.h"
#include "Types.h"
#include "IRadio.h"
#include "IChannel.h"
#include "ChannelManager.h"
#include "UIManager.h"


#define LCD_BL_PIN 4
#define GLCD_ROTATE_180

// D0, D1, D2, D3, D4, D5, D6, D7
// EN, CS1, CS2, DI, RW
U8GLIB_KS0108_128 glcd(
  38, 41, 40, 37, 36, 35, 34, 33,
  14, 32, 31, 30, 15
);

UniversalButtons uiButtons;


void setup()
{
  setup_serial_logger();
  
  ChannelManager::Instance().addChannel(new IChannel("Throttle", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new IChannel("Yaw", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new IChannel("Pitch", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new IChannel("Roll", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new IChannel("Camera X", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new IChannel("Camera Y", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new IChannel("Mode", 0, 0, 0, 2));
  ChannelManager::Instance().addChannel(new IChannel("Mode 2", 0, 0, 0, 2));

  uiButtons.setDefaultButtonConfig(1, 1);

  uiButtons.addButton(BUTTON_LEFT, 47);
  uiButtons.addButton(BUTTON_UP, 49);
  uiButtons.addButton(BUTTON_DOWN, 45);
  uiButtons.addButton(BUTTON_RIGHT, 43);
  uiButtons.addButton(BUTTON_SELECT, 44); // F1
  uiButtons.addButton(BUTTON_MENU, 48);   // F2
  uiButtons.addButton(BUTTON_HOME, 42);   // F3
  uiButtons.addButton(BUTTON_BACK, 46);   // F4

  uiButtons.setStateChangeCallback(uiButtonHandle);

#ifdef GLCD_ROTATE_180
  glcd.setRot180();
#endif

  ui_init(&glcd);
}


void loop()
{
  uiButtons.poll();
  ui_update();
}


void uiButtonHandle(buttonid_t id, uint8_t state)
{
  // Ignore button releases
  if(!state)
    return;

  ui_handleButtonPress((uibutton_t)id);
}
