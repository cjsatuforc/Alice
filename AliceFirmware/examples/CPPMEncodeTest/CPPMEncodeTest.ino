/** @file */

#include <inttypes.h>

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoButton.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <TimerThree.h>

#include <cppm_encode.h>

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(9600);

  cppm_init();

  /* Stream 0 config */
  cppm_set_stream_enable(0, true);
  cppm_set_stream_pin(0, 10);
  cppm_set_stream_num_channels(0, 6);

  /* Stream 1 config */
  cppm_set_stream_enable(1, true);
  cppm_set_stream_pin(1, 6);
  cppm_set_stream_num_channels(1, 5);

  Serial.print("Start CPPM: ");
  Serial.println(cppm_start());

  /* Stream 0 channel values */
  cppm_set_stream_channel(0, 0, 1000);
  cppm_set_stream_channel(0, 1, 2000);
  cppm_set_stream_channel(0, 2, 1800);
  cppm_set_stream_channel(0, 3, 1400);
  cppm_set_stream_channel(0, 4, 1000);
  cppm_set_stream_channel(0, 5, 2000);

  /* Stream 1 channel values */
  cppm_set_stream_channel(1, 0, 1400);
  cppm_set_stream_channel(1, 1, 1600);
  cppm_set_stream_channel(1, 2, 1100);
  cppm_set_stream_channel(1, 3, 1900);
  cppm_set_stream_channel(1, 4, 2000);
}

/**
 * @brief Main loop.
 */
void loop()
{
}
