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
#include "ControlMapping.h"
#include "ControlMappingManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "ControlMapping.h"

#include "ArduinoJoystick.h"
#include "LinearTransform.h"
#include "PPMRadio.h"


// D0, D1, D2, D3, D4, D5, D6, D7
// EN, CS1, CS2, DI, RW
U8GLIB_KS0108_128 glcd(
  30, 31, 32, 33, 34, 35, 36, 37,
  42, 38, 39, 40, 41
);
#define GLCD_ROTATE_180

PPMRadio radio(11, 4);

LinearTransform transformA(-150, 150, 1500, 2500);
LinearTransform transformB(0, 150, 1500, 2500);

void setup()
{
  setup_serial_logger();

  InputManager::Instance().addUIButton(BUTTON_LEFT, 25);
  InputManager::Instance().addUIButton(BUTTON_UP, 23);
  InputManager::Instance().addUIButton(BUTTON_DOWN, 27);
  InputManager::Instance().addUIButton(BUTTON_RIGHT, 29);
  InputManager::Instance().addUIButton(BUTTON_SELECT, 26); // F1
  InputManager::Instance().addUIButton(BUTTON_MENU, 22);   // F2
  InputManager::Instance().addUIButton(BUTTON_HOME, 28);   // F3
  InputManager::Instance().addUIButton(BUTTON_BACK, 24);   // F4

  ArduinoJoystick * joystick = NULL;

  joystick = new ArduinoJoystick(0, 0);
  joystick->setTransformation(&transformA);
  InputManager::Instance().addControl(joystick);

  joystick = new ArduinoJoystick(1, 1);
  joystick->setTransformation(&transformB);
  InputManager::Instance().addControl(joystick);

  joystick = new ArduinoJoystick(2, 2);
  joystick->setTransformation(&transformA);
  InputManager::Instance().addControl(joystick);

  joystick = new ArduinoJoystick(3, 3);
  joystick->setTransformation(&transformA);
  InputManager::Instance().addControl(joystick);

  ChannelManager::Instance().addChannel(new Channel(0, "Throttle"));
  ChannelManager::Instance().addChannel(new Channel(1, "Yaw"));
  ChannelManager::Instance().addChannel(new Channel(2, "Pitch"));
  ChannelManager::Instance().addChannel(new Channel(3, "Roll"));

  ControlMappingManager::Instance().addMapping(new ControlMapping(1, 0, CONTROLMODE_SET));
  ControlMappingManager::Instance().addMapping(new ControlMapping(0, 1, CONTROLMODE_SET));
  ControlMappingManager::Instance().addMapping(new ControlMapping(2, 2, CONTROLMODE_SET));
  ControlMappingManager::Instance().addMapping(new ControlMapping(3, 3, CONTROLMODE_SET));

  radio.open();
  radio.pair();

#ifdef GLCD_ROTATE_180
  glcd.setRot180();
#endif

  ui_init(&glcd);
}


void loop()
{
  InputManager::Instance().poll();
  ui_update();

  ChannelManager::Instance().sendToRadio(radio);
}
