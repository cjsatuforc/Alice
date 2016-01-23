/** @file */

#line 2 "SDTest.ino"

#include "SPI.h"
#include "SdFat.h"

#include <ArduinoUnit.h>
#include <AliceTest.h>

#include <SDUtils.h>

/**
 * @brief Tests directory listing.
 */
test(directory_list)
{
  SDUtils sd;

  size_t len = sd.directoryCount("/SYSTEM/INPUT");
  assertEqual(len, 10);

  len *= 13;
  char listing[len];
  size_t n = sd.listDirectory("/SYSTEM/INPUT", listing, len);

  assertEqual(n, 45);
  assertEqual(strcmp(listing, "AIL,RUD,SW1C,POT2,POT3,POT1,SW1A,SW1B,ELE,THR"), 0);
}

/**
 * @brief Test gettting a list of config options.
 */
test(config_list)
{
  SDUtils sd;

  size_t len = 100;
  char listing[len];
  size_t n = sd.listConfigurations("/SYSTEM/INPUT/AIL", listing, len);

  assertEqual(n, 13);
  assertEqual(strcmp(listing, "name,type,pin"), 0);
}

/**
 * @brief Tests getting the values of configs.
 */
test(config_get)
{
  SDUtils sd;

  size_t len = 20;
  char value[len];
  size_t n = sd.getConfigValue("/SYSTEM/INPUT/AIL", "type", value, len);

  assertEqual(n, 5);
  assertEqual(strcmp(value, "stick"), 0);
}

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;
}

/**
 * @brief Test runner.
 */
void loop()
{
  Test::run();
}
