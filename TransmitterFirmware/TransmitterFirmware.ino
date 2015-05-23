#include <inttypes.h>

#include <UniversalInputManager.h>
#include <UniversalInputTypes.h>
#include <IButton.h>
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

UniversalInputManager uiButtons;
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

  uiButtons.addNewButton(BUTTON_LEFT, 47);
  uiButtons.addNewButton(BUTTON_UP, 49);
  uiButtons.addNewButton(BUTTON_DOWN, 45);
  uiButtons.addNewButton(BUTTON_RIGHT, 43);
  uiButtons.addNewButton(BUTTON_SELECT, 44); // F1
  uiButtons.addNewButton(BUTTON_MENU, 48);   // F2
  uiButtons.addNewButton(BUTTON_HOME, 42);   // F3
  uiButtons.addNewButton(BUTTON_BACK, 46);   // F4

  uiButtons.setCallback(uiButtonHandle);

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


void uiButtonHandle(inputtype_t type, IInputDevice * device)
{
  if(type == UIT_BUTTON)
  {
    IButton * button = (IButton *) device;
    if(button->isActive())
      ui_handleButtonPress((uibutton_t) button->getID());
  }  
}
