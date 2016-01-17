/** @file */

#include "IMixerOperation.h"

#include "InputManager.h"
#include "IInput.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param mappedInputName Name of the input device used in this mix
 * @param weight Weight associated with this mix
 */
IMixerOperation::IMixerOperation(char * name, char * mappedInputName, cevalue_t weight)
  : AliceObject(name)
  , m_mappedInputName(mappedInputName)
  , m_weight(weight)
{
}

IMixerOperation::~IMixerOperation()
{
}

/**
 * @brief Gets the name of the input device used in this device.
 * @return Input device name
 */
const char * IMixerOperation::getMappedInputName() const
{
  return m_mappedInputName;
}

/**
 * @brief Gets the value of the mapped input device.
 * @return Value of input device
 */
cevalue_t IMixerOperation::getInputValue() const
{
  IInput * in = InputManager::Instance().getInput(m_mappedInputName);
  if (in == NULL)
    return US_CENTRE;

  return in->value();
}

/**
 * @brief Evaluates the operation.
 * @param lastValue Current mix channel value
 * @return New mix channel value
 */
cevalue_t IMixerOperation::evaluate(cevalue_t lastValue) const
{
  cevalue_t evaluated = doEvaluation(lastValue);

  // Clamp to range
  if (evaluated < CE_LOW)
    evaluated = CE_LOW;
  else if (evaluated > CE_HIGH)
    evaluated = CE_HIGH;

  return evaluated;
}

/**
 * @brief Gets the eight associated with this mix.
 * @return Weight
 */
cevalue_t IMixerOperation::getWeight() const
{
  return m_weight;
}
