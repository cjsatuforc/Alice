/** @file */

#ifndef _ALICE_SWITCHINPUT_H_
#define _ALICE_SWITCHINPUT_H_

#include "IInput.h"

#include <ArduinoButton.h>

/**
 * @class SwitchInput
 * @brief Represents a two position switch (or one position of a multiple
 *        position switch).
 */
class SwitchInput : public IInput
{
public:
  SwitchInput(char *name, uint8_t ioPin, bool pullUp = true, bool activeLow = true);
  virtual ~SwitchInput();

  cevalue_t value();

private:
  ArduinoButton m_button;
};

#endif
