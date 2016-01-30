/** @file */

#include <inttypes.h>

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoButton.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <TimerThree.h>

#include <SerialOutput.h>
#include <PPMOutput.h>

SerialOutput serialOut("serialOut", 2, 7, Serial); //!< Serial output device

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(115200);

  usvalue_t values[] = {1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000};

  serialOut.setValues(values, 11);

  serialOut.tx();
}

/**
 * @brief Main loop.
 */
void loop()
{
}
