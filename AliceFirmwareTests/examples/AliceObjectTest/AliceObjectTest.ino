/** @file */

#line 2 "AliceObjectTest.ino"

#include <ArduinoUnit.h>

#include <AliceObject.h>

test(object_name)
{
  AliceObject o("test");
  assertTrue(strcmp(o.getName(), "test") == 0);
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
