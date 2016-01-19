/** @file */

#ifndef _ALICE_IINPUT_H_
#define _ALICE_IINPUT_H_

#include "AliceTypes.h"
#include "AliceObject.h"

/**
 * @enum InputType
 * @brief Represents the type of input device.
 */
enum InputType
{
  INPUT_STICK,
  INPUT_POT,
  INPUT_SWITCH,
  INPUT_MULTIPOS
};

/**
 * @class IInput
 * @brief Represents an input device
 */
class IInput : public AliceObject
{
public:
  virtual ~IInput();

  InputType type() const;

  /**
   * @brief Gets the current value of the input device.
   * @return Zero centred value
   */
  virtual cevalue_t value() const = 0;

protected:
  IInput(char *name, InputType type);

private:
  const InputType m_type; //!< Type of device
};

#endif
