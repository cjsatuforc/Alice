/** @file */

#include <inttypes.h>

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoButton.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <TimerThree.h>

#include <Radio.h>

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(115200);

  Radio::Instance().init();
}

/**
 * @brief Main loop.
 */
void loop()
{
  Radio::Instance().update();
}
