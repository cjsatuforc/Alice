/** @file */

#line 2 "MixerTest.ino"

#include <ArduinoUnit.h>

#include <Mixer.h>
#include <MixerChannel.h>
#include <IMixerOperation.h>

/**
 * @brief Tests creation of an empty Mixer.
 */
test(create_empty_mixer)
{
  Mixer m("test mixer", 5);

  // Default channels
  for (int i = 0; i < 5; i++)
    assertTrue(m.getChannel(i) == NULL);
}

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(9600);
  while(!Serial);
}

/**
 * @brief Test runner.
 */
void loop()
{
  Test::run();
}
