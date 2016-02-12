/** @file */

#include <inttypes.h>

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoButton.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <TimerThree.h>

#include <Radio.h>
#include <JoystickInput.h>
#include <PotentiometerInput.h>
#include <SwitchInput.h>

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(115200);

  Radio::Instance().addInput(new JoystickInput("roll", 0, 385, 512, 640));
  Radio::Instance().addInput(new JoystickInput("pitch", 1, 385, 512, 640));
  Radio::Instance().addInput(new JoystickInput("throttle", 2, 385, 512, 640, true));
  Radio::Instance().addInput(new JoystickInput("yaw", 3, 385, 512, 640, true));

  Radio::Instance().addInput(new PotentiometerInput("pot1", 4));
  Radio::Instance().addInput(new PotentiometerInput("pot2", 5));
  Radio::Instance().addInput(new PotentiometerInput("pot3", 6));

  Radio::Instance().addInput(new SwitchInput("sw1u", 34));
  Radio::Instance().addInput(new SwitchInput("sw1d", 32));

  Radio::Instance().addInput(new SwitchInput("sw2u", 36));
  Radio::Instance().addInput(new SwitchInput("sw2d", 30));

  Radio::Instance().addInput(new SwitchInput("sw3u", 37));
  Radio::Instance().addInput(new SwitchInput("sw3d", 31));

  Radio::Instance().addInput(new SwitchInput("sw4u", 35));
  Radio::Instance().addInput(new SwitchInput("sw4d", 33));

  Radio::Instance().addInput(new SwitchInput("sw5u", 28)); //TODO
  Radio::Instance().addInput(new SwitchInput("sw5d", 22));

  Radio::Instance().addInput(new SwitchInput("sw6u", 23));
  Radio::Instance().addInput(new SwitchInput("sw6d", 29));

  Radio::Instance().addInput(new SwitchInput("sw7u", 24));

  Radio::Instance().addInput(new SwitchInput("sw8u", 27));
}

/**
 * @brief Prints the value of an input device.
 * @param name Device name
 */
void printInputValue(const char *name)
{
  Serial.print(name);
  Serial.print(": \t\t");
  IInput * in = Radio::Instance().getInput(name);
  if (in == NULL)
    Serial.println("fail");
  else
    Serial.println(in->value());
}

/**
 * @brief Main loop.
 */
void loop()
{
  printInputValue("roll");
  printInputValue("pitch");
  printInputValue("throttle");
  printInputValue("yaw");

  printInputValue("pot1");
  printInputValue("pot2");
  printInputValue("pot3");

  printInputValue("sw1u");
  printInputValue("sw1d");
  printInputValue("sw2u");
  printInputValue("sw2d");
  printInputValue("sw3u");
  printInputValue("sw3d");
  printInputValue("sw4u");
  printInputValue("sw4d");
  printInputValue("sw5u");
  printInputValue("sw5d");
  printInputValue("sw6u");
  printInputValue("sw6d");
  printInputValue("sw7u");
  printInputValue("sw8u");

  Serial.println("==========\n");

  /* delay(10); */
}
