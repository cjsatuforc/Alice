#include <inttypes.h>

#include <UniversalInput.h>
#include <UniversalButtons.h>
#include <U8glib.h>
#include <M2tk.h>
#include <utility/m2ghu8g.h>

#include "SerialLog.h"
#include "Types.h"
#include "IRadio.h"
#include "Channel.h"
#include "ChannelManager.h"
#include "UIManager.h"
#include "ControlMapping.h"

#include "DebugRadio.h"


// D0, D1, D2, D3, D4, D5, D6, D7
// EN, CS1, CS2, DI, RW
U8GLIB_KS0108_128 glcd(
  38, 41, 40, 37, 36, 35, 34, 33,
  14, 32, 31, 30, 15
);
#define LCD_BL_PIN 4
#define GLCD_ROTATE_180

UniversalButtons uiButtons;
DebugRadio radio;


void setup()
{
  setup_serial_logger();

  radio.open();
  radio.pair();

  ChannelManager::Instance().addChannel(new Channel("Throttle", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new Channel("Yaw", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new Channel("Pitch", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new Channel("Roll", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new Channel("Camera X", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new Channel("Camera Y", 0, 0, 1500, 2500));
  ChannelManager::Instance().addChannel(new Channel("Mode", 0, 0, 0, 2));
  ChannelManager::Instance().addChannel(new Channel("Mode 2", 0, 0, 0, 2));

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

  //ChannelManager::Instance().sendToRadio(radio);
}


void uiButtonHandle(buttonid_t id, uint8_t state)
{
  // Ignore button releases
  if(!state)
    return;

  ui_handleButtonPress((uibutton_t)id);
}
