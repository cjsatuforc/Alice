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
test(object_name)
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
