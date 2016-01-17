/** @file */

#line 2 "AliceObjectTest.ino"

#include <ArduinoUnit.h>

#include <AliceObject.h>
#include <AliceObjectList.h>

#include <MockInput.h>

/**
 * @brief Tests object names.
 */
test(object_name)
{
  AliceObject o("test");
  assertTrue(strcmp(o.getName(), "test") == 0);
}

test(object_list)
{
  AliceObjectList l(10);

  assertEqual(l.capacity(), 10);
  assertEqual(l.size(), 0);

  l.add(new MockInput("in1", INPUT_STICK, 1500));
  l.add(new MockInput("in2", INPUT_STICK, 2000));

  assertEqual(l.size(), 2);

  assertTrue(l.get("in1") != NULL);
  assertTrue(l.get("in2") != NULL);

  assertEqual(((MockInput *) l.get("in1"))->value(), 1500);
  assertEqual(((MockInput *) l.get("in2"))->value(), 2000);
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
