/** @file */

#include "PotentiometerInput.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param adcPin Arduino ADC pin number
 * @param adcLower Lower ADC reading
 * @param adcUpper Upper ADC reading
 * @param reverse Reverse the direction of the joystick
 * @param threshold Threshold for new value
 */
PotentiometerInput::PotentiometerInput(char *name, uint8_t adcPin, int16_t adcLower,
                                       int16_t adcUpper, bool reverse, uint8_t threshold)
    : IInput(name, INPUT_POT)
    , m_adcVCentre(adcLower + ((adcUpper - adcLower) / 2))
    , m_potentiometer(adcPin, adcPin)
    , m_transform(adcLower, adcUpper, -1000, 1000)
    , m_reverse(reverse)
{
  m_potentiometer.setThreshold(threshold);
  m_potentiometer.setPoints(adcLower, adcUpper);
  m_potentiometer.setTransformation(&m_transform);
}

PotentiometerInput::~PotentiometerInput()
{
  m_potentiometer.setTransformation(NULL);
}

/**
 * @copydoc IInput::value
 */
cevalue_t PotentiometerInput::value()
{
  m_potentiometer.poll();

  cevalue_t value = m_potentiometer.getValue();
  value /= 10.0;

  if (m_reverse)
    value = -value;

  return value;
}
