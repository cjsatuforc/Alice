/** @file */

#include <inttypes.h>

#include <SPI.h>
#include <SdFat.h>
#include <ArduinoButton.h>
#include <ArduinoJoystick.h>
#include <LinearTransform.h>
#include <TimerThree.h>

#include <Radio.h>
#include <Model.h>
#include <JoystickInput.h>
#include <PotentiometerInput.h>
#include <Mixer.h>
#include <MixerOperationAdd.h>
#include <SerialOutput.h>
#include <PPMOutput.h>
#include <cppm_encode.h>

#define NUM_CHANNELS 4

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(115200);
  cppm_init();

  /* INPUT */
  Radio::Instance().addInput(new PotentiometerInput("P1", 0));
  Radio::Instance().addInput(new PotentiometerInput("P2", 1));
  Radio::Instance().addInput(new PotentiometerInput("P3", 2));
  Radio::Instance().addInput(new JoystickInput("Roll", 3, 385, 512, 640));
  Radio::Instance().addInput(new JoystickInput("Pitch", 4, 385, 512, 640));
  Radio::Instance().addInput(new JoystickInput("Throttle", 5, 385, 512, 640, true));
  Radio::Instance().addInput(new JoystickInput("Yaw", 6, 385, 512, 640, true));

  /* MIXER */
  Mixer *mixer = new Mixer("Test Mixer", NUM_CHANNELS);

  MixerChannel *rollMix = new MixerChannel("Roll Mix", 1);
  rollMix->addOperation(new MixerOperationAdd("Roll Add", "Roll", 100));
  mixer->addChannel(0, rollMix);

  MixerChannel *pitchMix = new MixerChannel("Pitch Mix", 1);
  pitchMix->addOperation(new MixerOperationAdd("Pitch Add", "Pitch", 100));
  mixer->addChannel(1, pitchMix);

  MixerChannel *throttleMix = new MixerChannel("Throttle Mix", 1);
  throttleMix->addOperation(new MixerOperationAdd("Throttle Add", "Throttle", 100));
  mixer->addChannel(2, throttleMix);

  MixerChannel *yawMix = new MixerChannel("Yaw Mix", 1);
  yawMix->addOperation(new MixerOperationAdd("Yaw Add", "Yaw", 100));
  mixer->addChannel(3, yawMix);

  MixerChannel *p1Mix = new MixerChannel("P1 Mix", 1);
  p1Mix->addOperation(new MixerOperationAdd("P1 Add", "P1", 100));
  mixer->addChannel(4, p1Mix);

  MixerChannel *p2Mix = new MixerChannel("P2 Mix", 1);
  p2Mix->addOperation(new MixerOperationAdd("P2 Add", "P2", 100));
  mixer->addChannel(5, p2Mix);

  MixerChannel *p3Mix = new MixerChannel("P3 Mix", 1);
  p3Mix->addOperation(new MixerOperationAdd("P3 Add", "P3", 100));
  mixer->addChannel(6, p3Mix);

  Model *model = new Model("Test Model", 2);
  model->setMixer(mixer);

  /* OUTPUT (6 channels) */
  model->addOutput(new SerialOutput("Debug Output", 0, 8, Serial));
  /* model->addOutput(new PPMOutput("PPM Out", 0, 5, 10)); */

  Serial.println(Radio::Instance().setModel(model));
}

/**
 * @brief Main loop.
 */
void loop()
{
  Radio::Instance().update();
}
