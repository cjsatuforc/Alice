/** @file */

#include <inttypes.h>

#include <SPI.h>
#include <SdFat.h>

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
