/** @file */

#include <IOutput.h>
#include <MockOutput.h>

#include <unity.h>

#ifdef UNIT_TEST

/**
 * @brief Tests setting values on an output device.
 */
void test_setting_values()
{
  MockOutput out1("out1", 2, 7);

  /* Test channel counts */
  TEST_ASSERT_EQUAL(out1.startChannel(), 2);
  TEST_ASSERT_EQUAL(out1.endChannel(), 7);
  TEST_ASSERT_EQUAL(out1.numChannels(), 6);

  /* Test initial values by index*/
  for (int i = 0; i < 6; i++)
    TEST_ASSERT_EQUAL(out1.valueByIndex(i), 1500);

  /* Test initial value by channel number */
  for (int i = 2; i <= 7; i++)
    TEST_ASSERT_EQUAL(out1.valueByChannel(i), 1500);

  /* Set values */
  usvalue_t vals[] = {1000, 1100, 1200, 1300, 1400, 1600, 1700, 1800, 1900, 2000};

  out1.setValues(vals, 10);

  /* Test values by index */
  TEST_ASSERT_EQUAL(out1.valueByIndex(0), 1200);
  TEST_ASSERT_EQUAL(out1.valueByIndex(1), 1300);
  TEST_ASSERT_EQUAL(out1.valueByIndex(2), 1400);
  TEST_ASSERT_EQUAL(out1.valueByIndex(3), 1600);
  TEST_ASSERT_EQUAL(out1.valueByIndex(4), 1700);
  TEST_ASSERT_EQUAL(out1.valueByIndex(5), 1800);

  /* Test values by channel number */
  TEST_ASSERT_EQUAL(out1.valueByChannel(2), 1200);
  TEST_ASSERT_EQUAL(out1.valueByChannel(3), 1300);
  TEST_ASSERT_EQUAL(out1.valueByChannel(4), 1400);
  TEST_ASSERT_EQUAL(out1.valueByChannel(5), 1600);
  TEST_ASSERT_EQUAL(out1.valueByChannel(6), 1700);
  TEST_ASSERT_EQUAL(out1.valueByChannel(7), 1800);
}

void process()
{
  UNITY_BEGIN();
  RUN_TEST(test_setting_values);
  UNITY_END();
}

#ifdef ARDUINO
#include <Arduino.h>
void setup()
{
  process()
}
void loop()
{
}
#else
int main(int argc, char **argv)
{
  process();
  return 0;
}
#endif

#endif
