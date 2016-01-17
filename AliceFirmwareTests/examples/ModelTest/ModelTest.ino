/** @file */

#line 2 "ModelTest.ino"

#include <ArduinoUnit.h>

#include <Model.h>

test(create_empty_model)
{
  Model m("test model", 2);

  // Default outputs
  for (int i = 0; i < 2; i++)
    assertTrue(m.getOutput(i) == NULL);
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
