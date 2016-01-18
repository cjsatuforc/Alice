/** @file */

#line 2 "MockItemsTest.ino"

#include <ArduinoUnit.h>
#include <AliceTest.h>

#include <IInput.h>
#include <MockInput.h>

/**
 * @brief Tests the MockInput class.
 */
test(mock_input)
{
  MockInput in1("mock_in1", INPUT_STICK, 1500);
  assertEqual(in1.type(), INPUT_STICK);
  assertEqual(in1.value(), 1500);

  MockInput in2("mock_in2", INPUT_SWITCH, 2000);
  assertEqual(in2.type(), INPUT_SWITCH);
  assertEqual(in2.value(), 2000);
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
