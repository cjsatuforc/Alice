#include <inttypes.h>

#include <UniversalInputManager.h>
#include <UniversalInputTypes.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>

#include "Types.h"
#include "IRadio.h"
#include "Channel.h"
#include "ChannelManager.h"
#include "ControlMapping.h"
#include "ControlMappingManager.h"
#include "InputManager.h"
#include "ControlMapping.h"
#include "PPMRadio.h"

#include "SerialRadio.h"
#include "NullRadio.h"


//PPMRadio g_radio(11, 4);
SerialRadio g_radio(Serial);
//NullRadio g_radio;

LinearTransform transformA(-150, 150, 1000, 2000);
LinearTransform transformB(-150, 150, 1000, 2000);


void setup()
{
	Serial.begin(115200);

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

  g_radio.open();
  g_radio.pair();
}


void loop()
{
  InputManager::Instance().poll();
  ChannelManager::Instance().sendToRadio(g_radio);
}
