/** @file */

#line 2 "ModelTest.ino"

#include <ArduinoUnit.h>
#include <AliceTest.h>

#include <Model.h>

/**
 * @brief Tests creation of an empty Model.
 */
test(create_empty_model)
{
  Model m("test model", 2);
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
