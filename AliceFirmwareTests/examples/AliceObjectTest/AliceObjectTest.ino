/** @file */

#line 2 "AliceObjectTest.ino"

#include <ArduinoUnit.h>

#include <AliceObject.h>

/**
 * @brief Tests object names.
 */
test(object_name)
{
  AliceObject o("test");
  assertTrue(strcmp(o.getName(), "test") == 0);
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
