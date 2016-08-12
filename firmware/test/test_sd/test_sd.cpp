/** @file */

#ifdef UNIT_TEST

#include <Unity.h>

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoButton.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <TimerThree.h>

#include <ArduinoUnit.h>
#include <AliceTest.h>

#include <SDUtils.h>

/**
 * @brief Tests directory listing.
 */
void test_directory_list()
{
  SDUtils sd;

  size_t len = sd.directoryCount("/SYSTEM/INPUT");
  assertEqual(len, 10);

  len *= 13;
  char listing[len];
  size_t n = sd.listDirectory("/SYSTEM/INPUT", listing, len);

  TEST_ASSERT_EQUAL(n, 45);
  TEST_ASSERT_EQUAL(strcmp(listing, "AIL,RUD,SW1C,POT2,POT3,POT1,SW1A,SW1B,ELE,THR"), 0);
}

/**
 * @brief Test gettting a list of config options.
 */
void test_config_list()
{
  SDUtils sd;

  size_t len = 100;
  char listing[len];
  size_t n = sd.listConfigurations("/SYSTEM/INPUT/AIL", listing, len);

  TEST_ASSERT_EQUAL(n, 13);
  TEST_ASSERT_EQUAL(strcmp(listing, "name,type,pin"), 0);
}

/**
 * @brief Tests getting the values of configs.
 */
void test_config_get()
{
  SDUtils sd;

  size_t len = 20;
  char value[len];
  size_t n = sd.getConfigValue("/SYSTEM/INPUT/AIL", "type", value, len);

  TEST_ASSERT_EQUAL(n, 5);
  TEST_ASSERT_EQUAL(strcmp(value, "stick"), 0);
}

void process()
{
  UNITY_BEGIN();
  RUN_TEST(test_directory_list);
  RUN_TEST(test_config_list;
  RUN_TEST(test_config_get);
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
