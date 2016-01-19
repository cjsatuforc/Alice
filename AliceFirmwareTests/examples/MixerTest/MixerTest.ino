/** @file */

#line 2 "MixerTest.ino"

#include <ArduinoUnit.h>
#include <AliceTest.h>

#include <MockInput.h>

#include <InputManager.h>
#include <Mixer.h>
#include <MixerChannel.h>
#include <MixerOperationAdd.h>
#include <MixerOperationAddIf.h>
#include <MixerOperationReplaceIf.h>

/**
 * @brief Tests creation of an empty Mixer.
 */
test(create_empty_mixer)
{
  Mixer m("test mixer", 5);

  // Default channels
  for (int i = 0; i < 5; i++)
    assertTrue(m.getChannel(i) == NULL);
}

/**
 * @brief Tests filling an array of the exact correct size with evaluated
 *        timing values from a Mixer.
 */
test(evaluation_fill_array_timing)
{
  Mixer m("test mixer", 5);
  m.addChannel(0, new MixerChannel("channel 0", 0, -100.0));
  m.addChannel(1, new MixerChannel("channel 1", 0, -50.0));
  m.addChannel(2, new MixerChannel("channel 2", 0, 50.0));
  m.addChannel(3, new MixerChannel("channel 3", 0, 100.0));

  usvalue_t values[4];
  assertEqual(m.fillOutputArrayTiming(values, 4), 4);

  assertClose(values[0], 1000);
  assertClose(values[1], 1250);
  assertClose(values[2], 1750);
  assertClose(values[3], 2000);
}

/**
 * @brief Tests filling an array of the exact correct size with evaluated
 *        values from a Mixer.
 */
test(evaluation_fill_array_samesize)
{
  Mixer m("test mixer", 5);
  m.addChannel(0, new MixerChannel("channel 0", 0, -100.0));
  m.addChannel(1, new MixerChannel("channel 1", 0, -50.0));
  m.addChannel(2, new MixerChannel("channel 2", 0, 50.0));
  m.addChannel(3, new MixerChannel("channel 3", 0, 100.0));

  cevalue_t values[4];
  assertEqual(m.fillOutputArrayZeroCentre(values, 4), 4);

  assertClose(values[0], -100.0);
  assertClose(values[1], -50.0);
  assertClose(values[2], 50.0);
  assertClose(values[3], 100.0);
}

/**
 * @brief Tests filling an array of greater then required size with evaluated
 *        values from a Mixer.
 */
test(evaluation_fill_array_largesize)
{
  Mixer m("test mixer", 5);
  m.addChannel(0, new MixerChannel("channel 0", 0, -100.0));
  m.addChannel(1, new MixerChannel("channel 1", 0, -50.0));
  m.addChannel(2, new MixerChannel("channel 2", 0, 50.0));
  m.addChannel(3, new MixerChannel("channel 3", 0, 100.0));

  cevalue_t values[8];
  assertEqual(m.fillOutputArrayZeroCentre(values, 8), 4);

  assertClose(values[0], -100.0);
  assertClose(values[1], -50.0);
  assertClose(values[2], 50.0);
  assertClose(values[3], 100.0);
}

/**
 * @brief Tests filling an array of less then required size with evaluated
 *        values from a Mixer.
 */
test(evaluation_fill_array_smallsize)
{
  Mixer m("test mixer", 5);
  m.addChannel(0, new MixerChannel("channel 0", 0, -100.0));
  m.addChannel(1, new MixerChannel("channel 1", 0, -50.0));
  m.addChannel(2, new MixerChannel("channel 2", 0, 50.0));
  m.addChannel(3, new MixerChannel("channel 3", 0, 100.0));

  cevalue_t values[2];
  assertEqual(m.fillOutputArrayZeroCentre(values, 2), 2);

  assertClose(values[0], -100.0);
  assertClose(values[1], -50.0);
}

/**
 * @brief Tests creation of an empty MixerChannel.
 */
test(create_empty_channel)
{
  MixerChannel c("test channel", 10);
  assertEqual(c.numOperations(), 0);
  assertClose(c.initialValue(), 0.0);
}

/**
 * @brief Tests evaluation of a MixerChannel for a basic stick channel with
 *        weighting.
 */
test(channel_evaluation_add)
{
  MockInput *in = new MockInput("test_stick_1", INPUT_STICK, -100.0);
  InputManager::Instance().addInput(in);

  MixerChannel c("test channel", 10);

  c.addOperation(new MixerOperationAdd("stick_add", "test_stick_1", 90));
  assertEqual(c.numOperations(), 1);

  /* -100 * 0.9 = -90 */
  in->setValue(-100.0);
  assertClose(c.evaluate(), -90.0);

  /* 0 * 0.9 = 0 */
  in->setValue(0.0);
  assertClose(c.evaluate(), 0.0);

  /* 100 * 0.9 = 90 */
  in->setValue(100.0);
  assertClose(c.evaluate(), 90.0);
}
/**
 * @brief Tests evaluation of a MixerChannel with several switches each setting
 *        a different value.
 */
test(channel_evaluation_replaceif)
{
  MockInput *in1 = new MockInput("replaceif_test_switch_1", INPUT_SWITCH, 0.0);
  MockInput *in2 = new MockInput("replaceif_test_switch_2", INPUT_SWITCH, 0.0);
  MockInput *in3 = new MockInput("replaceif_test_switch_3", INPUT_SWITCH, 0.0);
  InputManager::Instance().addInput(in1);
  InputManager::Instance().addInput(in2);
  InputManager::Instance().addInput(in3);

  MixerChannel c("test channel", 10);

  c.addOperation(new MixerOperationReplaceIf("switch_1", "replaceif_test_switch_1", -50, 95, 10));
  c.addOperation(new MixerOperationReplaceIf("switch_2", "replaceif_test_switch_2", 25, 95, 10));
  c.addOperation(new MixerOperationReplaceIf("switch_3", "replaceif_test_switch_3", 75, 95, 10));
  assertEqual(c.numOperations(), 3);

  /* Default value if none are on */
  in1->setValue(10.0);
  in2->setValue(10.0);
  in3->setValue(10.0);
  assertClose(c.evaluate(), 0.0);

  /* Switch 1 on */
  in1->setValue(100.0);
  in2->setValue(10.0);
  in3->setValue(10.0);
  assertClose(c.evaluate(), -50.0);

  /* Switch 2 on */
  in1->setValue(10.0);
  in2->setValue(100.0);
  in3->setValue(10.0);
  assertClose(c.evaluate(), 25.0);

  /* Switch 3 on */
  in1->setValue(10.0);
  in2->setValue(10.0);
  in3->setValue(100.0);
  assertClose(c.evaluate(), 75.0);

  /* If all are on, last added gets priority */
  in1->setValue(100.0);
  in2->setValue(100.0);
  in3->setValue(100.0);
  assertClose(c.evaluate(), 75.0);
}

/**
 * @brief Test evaluation of a MixerChannel with several switches each adding a
 *        given value to the channel.
 *
 * For example, using two 3-position switches to select a combination of
 * pitch/roll/yaw and P/I/D for PID tuning.
 */
test(channel_evaluation_addif)
{
  MockInput *in1 = new MockInput("addif_test_switch_1", INPUT_SWITCH, 0.0);
  MockInput *in2 = new MockInput("addif_test_switch_2", INPUT_SWITCH, 0.0);
  MockInput *in3 = new MockInput("addif_test_switch_3", INPUT_SWITCH, 0.0);
  InputManager::Instance().addInput(in1);
  InputManager::Instance().addInput(in2);
  InputManager::Instance().addInput(in3);

  MixerChannel c("test channel", 10);

  c.addOperation(new MixerOperationAddIf("switch_1", "addif_test_switch_1", -50, 95, 10));
  c.addOperation(new MixerOperationAddIf("switch_2", "addif_test_switch_2", 25, 95, 10));
  c.addOperation(new MixerOperationAddIf("switch_3", "addif_test_switch_3", 75, 95, 10));
  assertEqual(c.numOperations(), 3);

  /* 0 = 0 */
  in1->setValue(10.0);
  in2->setValue(10.0);
  in3->setValue(10.0);
  assertClose(c.evaluate(), 0.0);

  /* 0 + (-50) = -50 */
  in1->setValue(100.0);
  in2->setValue(10.0);
  in3->setValue(10.0);
  assertClose(c.evaluate(), -50.0);

  /* 0 + 25 = 25 */
  in1->setValue(10.0);
  in2->setValue(100.0);
  in3->setValue(10.0);
  assertClose(c.evaluate(), 25.0);

  /* 0 + 75 = 75 */
  in1->setValue(10.0);
  in2->setValue(10.0);
  in3->setValue(100.0);
  assertClose(c.evaluate(), 75.0);

  /* 0 + (-50) + 25 + 75 = 50 */
  in1->setValue(100.0);
  in2->setValue(100.0);
  in3->setValue(100.0);
  assertClose(c.evaluate(), 50.0);

  /* 0 + 25 + 75 = 100 */
  in1->setValue(00.0);
  in2->setValue(100.0);
  in3->setValue(100.0);
  assertClose(c.evaluate(), 100.0);

  /* 0 + (-50) + 75 = 25 */
  in1->setValue(100.0);
  in2->setValue(00.0);
  in3->setValue(100.0);
  assertClose(c.evaluate(), 25.0);

  /* 0 + (-50) + 25 = -25 */
  in1->setValue(100.0);
  in2->setValue(100.0);
  in3->setValue(00.0);
  assertClose(c.evaluate(), -25.0);
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
