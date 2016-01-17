/** @file */

#line 2 "MockItemsTest.ino"

#include <ArduinoUnit.h>

#include <IInput.h>
#include <MockInput.h>

test(mock_input)
{
  MockInput in1("mock_in1", INPUT_STICK, 1500);
  assertEqual(in1.type(), INPUT_STICK);
  assertEqual(in1.value(), 1500);

  MockInput in2("mock_in2", INPUT_SWITCH, 2000);
  assertEqual(in2.type(), INPUT_SWITCH);
  assertEqual(in2.value(), 2000);
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
