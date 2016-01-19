/** @file */

#line 2 "OutputTest.ino"

#include <ArduinoUnit.h>
#include <AliceTest.h>

#include <IOutput.h>
#include <MockOutput.h>

/**
 * @brief Tests setting values on an output device.
 */
test(setting_values)
{
  MockOutput out1("out1", 2, 7);

  /* Test channel counts */
  assertEqual(out1.startChannel(), 2);
  assertEqual(out1.endChannel(), 7);
  assertEqual(out1.numChannels(), 6);

  /* Test initial values by index*/
  for (int i = 0; i < 6; i++)
    assertEqual(out1.valueByIndex(i), 1500);

  /* Test initial value by channel number */
  for (int i = 2; i <= 7; i++)
    assertEqual(out1.valueByChannel(i), 1500);

  /* Set values */
  usvalue_t vals[] = {1000, 1100, 1200, 1300,
                      1400, 1600, 1700, 1800,
                      1900, 2000};

  assertTrue(out1.setValues(vals, 10));

  /* Test values by index */
  assertEqual(out1.valueByIndex(0), 1200);
  assertEqual(out1.valueByIndex(1), 1300);
  assertEqual(out1.valueByIndex(2), 1400);
  assertEqual(out1.valueByIndex(3), 1600);
  assertEqual(out1.valueByIndex(4), 1700);
  assertEqual(out1.valueByIndex(5), 1800);

  /* Test values by channel number */
  assertEqual(out1.valueByChannel(2), 1200);
  assertEqual(out1.valueByChannel(3), 1300);
  assertEqual(out1.valueByChannel(4), 1400);
  assertEqual(out1.valueByChannel(5), 1600);
  assertEqual(out1.valueByChannel(6), 1700);
  assertEqual(out1.valueByChannel(7), 1800);
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
