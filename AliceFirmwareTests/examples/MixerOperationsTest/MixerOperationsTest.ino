/** @file */

#line 2 "MixerTest.ino"

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoButton.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <TimerThree.h>

#include <ArduinoUnit.h>
#include <AliceTest.h>

#include <MockInput.h>

#include <Radio.h>
#include <MixerOperationAdd.h>
#include <MixerOperationAddIf.h>
#include <MixerOperationReplaceIf.h>

/**
 * @brief Tests the add function.
 */
test(add)
{
  MixerOperationAdd add1("add1", "in_-100", 100.0);
  assertClose(add1.evaluate(0.0), -100.0);

  MixerOperationAdd add2("add2", "in_-100", 100.0);
  assertClose(add2.evaluate(100.0), 0.0);

  MixerOperationAdd add3("add3", "in_-100", 100.0);
  assertClose(add3.evaluate(-100.0), -100.0);

  MixerOperationAdd add4("add4", "in_0", 100.0);
  assertClose(add4.evaluate(0.0), 0.0);

  MixerOperationAdd add5("add5", "in_0", 100.0);
  assertClose(add5.evaluate(100.0), 100.0);

  MixerOperationAdd add6("add6", "in_0", 100.0);
  assertClose(add6.evaluate(-100.0), -100.0);

  MixerOperationAdd add7("add7", "in_100", 100.0);
  assertClose(add7.evaluate(0.0), 100.0);

  MixerOperationAdd add8("add8", "in_100", 100.0);
  assertClose(add8.evaluate(100.0), 100.0);

  MixerOperationAdd add9("add9", "in_100", 100.0);
  assertClose(add9.evaluate(-100.0), 0.0);
}

/**
 * @brief Tests the add-if operation.
 */
test(add_if)
{
  MixerOperationAddIf addif1("addif1", "in_50", 25.0, 52);
  assertClose(addif1.evaluate(50.0), 75.0);

  MixerOperationAddIf addif2("addif2", "in_50", 25.0, 53);
  assertClose(addif2.evaluate(50.0), 50.0);
}

/**
 * @brief Tests the replace-if operation.
 */
test(replace_if)
{
  MixerOperationReplaceIf repif1("repif1", "in_50", 25.0, 52);
  assertClose(repif1.evaluate(50.0), 25.0);

  MixerOperationReplaceIf repif2("repif2", "in_50", 25.0, 53);
  assertClose(repif2.evaluate(50.0), 50.0);
}

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  // Setup mock inputs
  Radio::Instance().addInput(new MockInput("in_-100", INPUT_STICK, -100.0));
  Radio::Instance().addInput(new MockInput("in_-50", INPUT_STICK, -50.0));
  Radio::Instance().addInput(new MockInput("in_0", INPUT_STICK, 0.0));
  Radio::Instance().addInput(new MockInput("in_50", INPUT_STICK, 50.0));
  Radio::Instance().addInput(new MockInput("in_100", INPUT_STICK, 100.0));
}

/**
 * @brief Test runner.
 */
void loop()
{
  Test::run();
}
