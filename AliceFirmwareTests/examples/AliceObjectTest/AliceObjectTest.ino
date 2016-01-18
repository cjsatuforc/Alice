/** @file */

#line 2 "AliceObjectTest.ino"

#include <ArduinoUnit.h>
#include <AliceTest.h>

#include <MockInput.h>

#include <AliceObject.h>
#include <AliceObjectList.h>

/**
 * @brief Tests object names.
 */
test(object_name)
{
  AliceObject o("test");
  assertTrue(strcmp(o.name(), "test") == 0);
}

/**
 * @brief Tests the AliceObjectList container when appending items.
 */
test(object_list_add)
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
 * @brief Tests the AliceObjectList container when adding items.
 */
test(object_list_set)
{
  AliceObjectList l(10);

  assertEqual(l.capacity(), 10);
  assertEqual(l.size(), 0);

  l.set(2, new MockInput("in1", INPUT_STICK, 1500));
  l.set(5, new MockInput("in2", INPUT_STICK, 2000));

  assertEqual(l.size(), 2);

  assertTrue(l.getByName("in1") != NULL);
  assertTrue(l.getByName("in2") != NULL);
  assertTrue(((MockInput *) l.getByName("nope")) == NULL);
  assertTrue(((MockInput *) l.get(0)) == NULL);
  assertTrue(((MockInput *) l.get(20)) == NULL);

  assertEqual(((MockInput *) l.getByName("in1"))->value(), 1500);
  assertEqual(((MockInput *) l.getByName("in2"))->value(), 2000);

  assertEqual(((MockInput *) l.get(2))->value(), 1500);
  assertEqual(((MockInput *) l.get(5))->value(), 2000);
}

/**
 * @brief Tests the ce_to_us() function.
 */
test(ce_to_us_test)
{
  assertEqual(ce_to_us(CE_HIGH), US_HIGH);
  assertEqual(ce_to_us(CE_CENTRE), US_CENTRE);
  assertEqual(ce_to_us(CE_LOW), US_LOW);
}

/**
 * @brief Tests the us_to_ce() function.
 */
test(us_to_ce_test)
{
  assertClose(us_to_ce(US_HIGH), CE_HIGH);
  assertClose(us_to_ce(US_CENTRE), CE_CENTRE);
  assertClose(us_to_ce(US_LOW), CE_LOW);
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
