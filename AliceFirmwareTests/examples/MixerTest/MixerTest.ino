/*! \file */

#line 2 "MixerTest.ino"

#include <ArduinoUnit.h>

#include <Mixer.h>
#include <MixerChannel.h>
#include <IMixerOperation.h>

test(create_empty_mixer)
{
  Mixer m("test mixer", 5);

  // Name
  char * expectedName = "test mixer";
  assertEqual(m.getName(), expectedName);

  // Default channels
  for (int i = 0; i < 5; i++)
    assertTrue(m.getChannel(i) == NULL);
}

void setup()
{
  Serial.begin(9600);
  while(!Serial);
}

void loop()
{
  Test::run();
}
