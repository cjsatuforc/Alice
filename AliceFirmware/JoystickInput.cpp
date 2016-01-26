/** @file */

#include "JoystickInput.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param adcPin Arduino ADC pin number
 * @param adcLower Lower ADC reading
 * @param adcCentre Centered ADC reading
 * @param adcUpper Upper ADC reading
 * @param reverse Reverse the direction of the joystick
 * @param threshold Threshold for new value
 */
JoystickInput::JoystickInput(char *name, uint8_t adcPin, uint8_t adcLower, uint8_t adcCentre,
                             uint8_t adcUpper, bool reverse, uint8_t threshold)
    : IInput(name, INPUT_STICK)
    , m_joystick(adcPin, adcPin)
    , m_transform(-adcLower + adcCentre, adcUpper - adcCentre, -1000, 1000)
    , m_reverse(reverse)
{
  m_joystick.setThreshold(threshold);
  m_joystick.setPoints(adcLower, adcCentre, adcUpper);
  m_joystick.setTransformation(&m_transform);
}

JoystickInput::~JoystickInput()
{
  m_joystick.setTransformation(NULL);
}

/**
 * @copydoc IInput::value
 */
cevalue_t JoystickInput::value()
{
  m_joystick.poll();

  cevalue_t value = m_joystick.getValue();
  value /= 10.0;

  if (m_reverse)
    value = -value;

  return value;
}
