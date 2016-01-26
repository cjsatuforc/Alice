/** @file */

#ifndef _ALICE_POTENTIOMETERINPUT_H_
#define _ALICE_POTENTIOMETERINPUT_H_

#include "IInput.h"

#include <ArduinoJoystick.h>
#include <LinearTransform.h>

/**
 * @class PotentiometerInput
 * @brief Represents an analog potentiometer.
 */
class PotentiometerInput : public IInput
{
public:
  PotentiometerInput(char *name, uint8_t adcPin, int16_t adcLower = 0, int16_t adcUpper = 1023,
                     bool reverse = false, uint8_t threshold = 1);
  virtual ~PotentiometerInput();

  cevalue_t value();

private:
  int16_t m_adcVCentre;
  ArduinoJoystick m_potentiometer;
  LinearTransform m_transform;
  bool m_reverse;
};

#endif
