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
#include <SwitchInput.h>
#include <Mixer.h>
#include <MixerOperationAdd.h>
#include <MixerOperationReplaceIf.h>
#include <SerialOutput.h>
#include <PPMOutput.h>
#include <cppm_encode.h>

#define NUM_CHANNELS 15

/**
 * @brief Setup routine.
 */
void setup()
{
  Serial.begin(115200);
  cppm_init();

  /* INPUT */
  Radio::Instance().addInput(new JoystickInput("Roll", 3, 385, 512, 640, true)); // TODO: adc pin
  Radio::Instance().addInput(new JoystickInput("Pitch", 4, 385, 512, 640, true)); // TODO: adc pin
  Radio::Instance().addInput(new JoystickInput("Throttle", 5, 385, 512, 640)); // TODO: adc pin
  Radio::Instance().addInput(new JoystickInput("Yaw", 6, 385, 512, 640));      // TODO: adc pin
  Radio::Instance().addInput(new PotentiometerInput("P1", 2, 0, 1023, true));
  Radio::Instance().addInput(new PotentiometerInput("P2", 1, 0, 1023, true));
  Radio::Instance().addInput(new PotentiometerInput("P3", 0, 0, 1023, true));
  Radio::Instance().addInput(new SwitchInput("SW1u", 34));
  Radio::Instance().addInput(new SwitchInput("SW1d", 32));
  Radio::Instance().addInput(new SwitchInput("SW2u", 36));
  Radio::Instance().addInput(new SwitchInput("SW2d", 30));
  Radio::Instance().addInput(new SwitchInput("SW3u", 37));
  Radio::Instance().addInput(new SwitchInput("SW3d", 31));
  Radio::Instance().addInput(new SwitchInput("SW4u", 35));
  Radio::Instance().addInput(new SwitchInput("SW4d", 33));
  Radio::Instance().addInput(new SwitchInput("SW5u", 28)); // TODO
  Radio::Instance().addInput(new SwitchInput("SW5d", 22));
  Radio::Instance().addInput(new SwitchInput("SW6u", 23));
  Radio::Instance().addInput(new SwitchInput("SW6d", 29));
  Radio::Instance().addInput(new SwitchInput("SW7", 24));
  Radio::Instance().addInput(new SwitchInput("SW8", 27));

  /* MIXER */
  Mixer *mixer = new Mixer("Test Mixer", NUM_CHANNELS);

  /* Roll */
  MixerChannel *rollMix = new MixerChannel("Roll Mix", 1);
  rollMix->addOperation(new MixerOperationAdd("Roll Add", "Roll", 100));
  mixer->addChannel(0, rollMix);

  /* Pitch */
  MixerChannel *pitchMix = new MixerChannel("Pitch Mix", 1);
  pitchMix->addOperation(new MixerOperationAdd("Pitch Add", "Pitch", 100));
  mixer->addChannel(1, pitchMix);

  /* Throttle */
  MixerChannel *throttleMix = new MixerChannel("Throttle Mix", 1);
  throttleMix->addOperation(new MixerOperationAdd("Throttle Add", "Throttle", 100));
  mixer->addChannel(2, throttleMix);

  /* Yaw */
  MixerChannel *yawMix = new MixerChannel("Yaw Mix", 1);
  yawMix->addOperation(new MixerOperationAdd("Yaw Add", "Yaw", 100));
  mixer->addChannel(3, yawMix);

  /* P1 */
  MixerChannel *p1Mix = new MixerChannel("P1 Mix", 1);
  p1Mix->addOperation(new MixerOperationAdd("P1 Add", "P1", 100));
  mixer->addChannel(4, p1Mix);

  /* P2 */
  MixerChannel *p2Mix = new MixerChannel("P2 Mix", 1);
  p2Mix->addOperation(new MixerOperationAdd("P2 Add", "P2", 100));
  mixer->addChannel(5, p2Mix);

  /* P3 */
  MixerChannel *p3Mix = new MixerChannel("P3 Mix", 1);
  p3Mix->addOperation(new MixerOperationAdd("P3 Add", "P3", 100));
  mixer->addChannel(6, p3Mix);

  /* SW1 */
  MixerChannel *sw1Mix = new MixerChannel("SW1 Mix", 2);
  sw1Mix->addOperation(new MixerOperationReplaceIf("SW1 Down", "SW1d", 100, 100));
  sw1Mix->addOperation(new MixerOperationReplaceIf("SW1 Up", "SW1u", -100, 100));
  mixer->addChannel(7, sw1Mix);

  /* SW2 */
  MixerChannel *sw2Mix = new MixerChannel("SW2 Mix", 2);
  sw2Mix->addOperation(new MixerOperationReplaceIf("SW2 Down", "SW2d", 100, 100));
  sw2Mix->addOperation(new MixerOperationReplaceIf("SW2 Up", "SW2u", -100, 100));
  mixer->addChannel(8, sw2Mix);

  /* SW3 */
  MixerChannel *sw3Mix = new MixerChannel("SW3 Mix", 2);
  sw3Mix->addOperation(new MixerOperationReplaceIf("SW3 Down", "SW3d", 100, 100));
  sw3Mix->addOperation(new MixerOperationReplaceIf("SW3 Up", "SW3u", -100, 100));
  mixer->addChannel(9, sw3Mix);

  /* SW4 */
  MixerChannel *sw4Mix = new MixerChannel("SW4 Mix", 2);
  sw4Mix->addOperation(new MixerOperationReplaceIf("SW4 Down", "SW4d", 100, 100));
  sw4Mix->addOperation(new MixerOperationReplaceIf("SW4 Up", "SW4u", -100, 100));
  mixer->addChannel(10, sw4Mix);

  /* SW5 */
  MixerChannel *sw5Mix = new MixerChannel("SW5 Mix", 2);
  sw5Mix->addOperation(new MixerOperationReplaceIf("SW5 Down", "SW5d", 100, 100));
  sw5Mix->addOperation(new MixerOperationReplaceIf("SW5 Up", "SW5u", -100, 100));
  mixer->addChannel(11, sw5Mix);

  /* SW6 */
  MixerChannel *sw6Mix = new MixerChannel("SW6 Mix", 2);
  sw6Mix->addOperation(new MixerOperationReplaceIf("SW6 Down", "SW6d", 100, 100));
  sw6Mix->addOperation(new MixerOperationReplaceIf("SW6 Up", "SW6u", -100, 100));
  mixer->addChannel(12, sw6Mix);

  /* SW7 */
  MixerChannel *sw7Mix = new MixerChannel("SW7 Mix", 1, -100);
  sw7Mix->addOperation(new MixerOperationReplaceIf("SW7", "SW7", 100, 100));
  mixer->addChannel(13, sw7Mix);

  /* SW8 */
  MixerChannel *sw8Mix = new MixerChannel("SW8 Mix", 1, -100);
  sw8Mix->addOperation(new MixerOperationReplaceIf("SW8", "SW8", 100, 100));
  mixer->addChannel(14, sw8Mix);

  Model *model = new Model("Test Model", 2);
  model->setMixer(mixer);

  /* OUTPUT (6 channels) */
  model->addOutput(new SerialOutput("Debug Output", 0, 14, Serial));
  /* model->addOutput(new PPMOutput("PPM Out", 0, 6, 10)); */

  Serial.println(Radio::Instance().setModel(model));
}

/**
 * @brief Main loop.
 */
void loop()
{
  Radio::Instance().update();
}
