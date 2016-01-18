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

/**
 * @brief Tests the AliceObjectList container.
 */
test(object_list)
{
  AliceObjectList l(10);

  assertEqual(l.capacity(), 10);
  assertEqual(l.size(), 0);

  l.add(new MockInput("in1", INPUT_STICK, 1500));
  l.add(new MockInput("in2", INPUT_STICK, 2000));

  assertEqual(l.size(), 2);

  assertTrue(l.getByName("in1") != NULL);
  assertTrue(l.getByName("in2") != NULL);
  assertTrue(((MockInput *) l.getByName("nope")) == NULL);
  assertTrue(((MockInput *) l.get(8)) == NULL);
  assertTrue(((MockInput *) l.get(20)) == NULL);

  assertEqual(((MockInput *) l.getByName("in1"))->value(), 1500);
  assertEqual(((MockInput *) l.getByName("in2"))->value(), 2000);

  assertEqual(((MockInput *) l.get(0))->value(), 1500);
  assertEqual(((MockInput *) l.get(1))->value(), 2000);
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
