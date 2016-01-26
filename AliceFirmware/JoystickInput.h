/** @file */

#ifndef _ALICE_JOYSTICKINPUT_H_
#define _ALICE_JOYSTICKINPUT_H_

#include "IInput.h"

#include <ArduinoJoystick.h>
#include <LinearTransform.h>

/**
 * @class JoystickInput
 * @brief Represents an analog joystick.
 */
class JoystickInput : public IInput
{
public:
  JoystickInput(char *name, uint8_t adcPin, int16_t adcLower = 0, int16_t adcCentre = 512,
                int16_t adcUpper = 1023, bool reverse = false, uint8_t threshold = 1);
  virtual ~JoystickInput();

  cevalue_t value();

private:
  ArduinoJoystick m_joystick;
  LinearTransform m_transform;
  bool m_reverse;
};

#endif
