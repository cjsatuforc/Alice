/*! \file */

#line 2 "MixerTest.ino"

#include <ArduinoUnit.h>

#define assertClose(a, b) assertTrue(abs(a - b) < 0.01)

#include <MockInput.h>
#include <InputManager.h>
#include <MixerOperationAdd.h>
#include <MixerOperationAddIf.h>
#include <MixerOperationReplaceIf.h>

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

test(add_if)
{
  MixerOperationAddIf addif1("addif1", "in_50", 25.0, 52);
  assertClose(addif1.evaluate(50.0), 75.0);

  MixerOperationAddIf addif2("addif2", "in_50", 25.0, 53);
  assertClose(addif2.evaluate(50.0), 50.0);
}

test(replace_if)
{
  MixerOperationReplaceIf repif1("repif1", "in_50", 25.0, 52);
  assertClose(repif1.evaluate(50.0), 25.0);

  MixerOperationReplaceIf repif2("repif2", "in_50", 25.0, 53);
  assertClose(repif2.evaluate(50.0), 50.0);
}

void setup()
{
  Serial.begin(9600);
  while(!Serial);

  // Setup mock inputs
  InputManager::Instance().addInput(new MockInput("in_-100", INPUT_STICK, -100.0));
  InputManager::Instance().addInput(new MockInput("in_-50", INPUT_STICK, -50.0));
  InputManager::Instance().addInput(new MockInput("in_0", INPUT_STICK, 0.0));
  InputManager::Instance().addInput(new MockInput("in_50", INPUT_STICK, 50.0));
  InputManager::Instance().addInput(new MockInput("in_100", INPUT_STICK, 100.0));
}

void loop()
{
  Test::run();
}
