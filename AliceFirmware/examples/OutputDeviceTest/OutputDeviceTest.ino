/** @file */

#include <inttypes.h>

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoButton.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <TimerThree.h>

#include <cppm_encode.h>
#include <SerialOutput.h>
#include <PPMOutput.h>

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(115200);

  /* Initialize CPPM driver (required when using PPMOutput, must be called
   * before PPMOutput is created) */
  cppm_init();

  SerialOutput serialOut("serialOut", 2, 7, Serial);
  PPMOutput ppmOut1("ppmOut1", 2, 7, 10);
  PPMOutput ppmOut2("ppmOut2", 0, 7, 6, HIGH);

  usvalue_t values[] = {1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000};

  serialOut.setValues(values, 11);
  ppmOut1.setValues(values, 11);
  ppmOut2.setValues(values, 11);

  /* Output stream numbers */
  Serial.print("ppmOut1 stream number: ");
  Serial.println(ppmOut1.streamNumber());
  Serial.print("ppmOut2 stream number: ");
  Serial.println(ppmOut2.streamNumber());

  serialOut.open();
  ppmOut1.open();
  ppmOut2.open();

  serialOut.tx();
  ppmOut1.tx();
  ppmOut2.tx();
}

/**
 * @brief Main loop.
 */
void loop()
{
}
