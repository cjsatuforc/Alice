/** @file */

#include "SwitchInput.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param ioPin Arduino pin number
 * @param pullUp If the input pin should be pulled up
 * @param activeLow If the switch is active when the input signal is low
 */
SwitchInput::SwitchInput(char *name, uint8_t ioPin, bool pullUp, bool activeLow)
    : IInput(name, INPUT_SWITCH)
    , m_button(ioPin, ioPin, activeLow, pullUp)
{
}

SwitchInput::~SwitchInput()
{
}

/**
 * @copydoc IInput::value
 */
cevalue_t SwitchInput::value()
{
  m_button.poll();

  cevalue_t value = -100.0;
  if (m_button.isActive())
    value = 100.0;

  return value;
}
