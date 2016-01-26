/** @file */

#include <inttypes.h>

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>

#include <Radio.h>
#include <JoystickInput.h>
#include <PotentiometerInput.h>

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
  Radio::Instance().addInput(new PotentiometerInput("pot3", 6, 0, 1023, true));
}

/**
 * @brief Prints the value of an input device.
 * @param name Device name
 */
void printInputValue(const char *name)
{
  Serial.print(name);
  Serial.print(": \t");
  Serial.println(Radio::Instance().getInput(name)->value());
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

  Serial.println("==========\n");

  delay(100);
}
