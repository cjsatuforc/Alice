#include <inttypes.h>

#include <UniversalInputManager.h>
#include <UniversalInputTypes.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <Nextion.h>

#include <AliceNextionUI.h>
#include <PageSplash.h>
#include <PageMain.h>
#include <PageMenu.h>
#include <PageTrim.h>
#include <PageChanSel.h>
#include <PageChanOpt.h>
#include <PageGeneralSett.h>

#include "AliceTypes.h"
#include "IRadio.h"
#include "Channel.h"
#include "ChannelManager.h"
#include "ControlMapping.h"
#include "ControlMappingManager.h"
#include "InputManager.h"
#include "ControlMapping.h"

/* #include "SerialRadio.h" */
/* SerialRadio g_radio(Serial); */
#include "NullRadio.h"
NullRadio g_radio;

Nextion nex(Serial1);
AliceNextionUI ui(nex);

void setup()
{
  while (!Serial);
  Serial.begin(9600);

  Serial1.begin(9600);
  Serial.println(nex.init());

  Serial.println(ui.addPage(new PageSplash(&ui)));
	Serial.println(ui.addPage(new PageMain(&ui)));
	Serial.println(ui.addPage(new PageMenu(&ui)));
	Serial.println(ui.addPage(new PageTrim(&ui)));
	Serial.println(ui.addPage(new PageChanSel(&ui)));
	Serial.println(ui.addPage(new PageChanOpt(&ui)));
	Serial.println(ui.addPage(new PageGeneralSett(&ui)));

	Serial.println(ui.showPage(PG_SPLASH));

  ArduinoJoystick *joystick = NULL;

  joystick = new ArduinoJoystick(0, 0);
  joystick->setTransformation(new LinearTransform(-150, 150, 1000, 2000));
  InputManager::Instance().addControl(joystick);

  joystick = new ArduinoJoystick(1, 1);
  joystick->setTransformation(new LinearTransform(-150, 150, 1000, 2000));
  InputManager::Instance().addControl(joystick);

  joystick = new ArduinoJoystick(2, 2);
  joystick->setTransformation(new LinearTransform(-150, 150, 1000, 2000));
  InputManager::Instance().addControl(joystick);

  joystick = new ArduinoJoystick(3, 3);
  joystick->setTransformation(new LinearTransform(-150, 150, 1000, 2000));
  InputManager::Instance().addControl(joystick);

  ChannelManager::Instance().addChannel(new Channel(2, "Throttle", 1000, 2000, 1500, true));
  ChannelManager::Instance().addChannel(new Channel(3, "Yaw"));
  ChannelManager::Instance().addChannel(new Channel(1, "Pitch"));
  ChannelManager::Instance().addChannel(new Channel(0, "Roll"));

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

  ui.poll();
  /* ui.update(); */
}