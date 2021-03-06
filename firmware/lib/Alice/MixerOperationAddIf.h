/** @file */

#ifndef _ALICE_MIXEROPERATIONADDIF_H_
#define _ALICE_MIXEROPERATIONADDIF_H_

#include "IMixerOperation.h"

/**
 * @class MixerOperationAddIf
 * @brief Mixer operation for conditional addition.
 *
 * If input value is equal to the equal parameter within tolerance then the
 * weight is added to the output value, otherwise the output is the input
 * value unchanged.
 */
class MixerOperationAddIf : public IMixerOperation
{
public:
  /**
   * @copydoc IMixerOperation::IMixerOperation
   * @param equal Value to check input value comparison with
   * @param tolerance Tolerance to use when checking equality
   */
  MixerOperationAddIf(char *name, char *mappedInputName, cevalue_t weight, cevalue_t equal,
                      cevalue_t tolerance = 5)
      : IMixerOperation(name, mappedInputName, weight)
      , m_equalToValue(equal)
      , m_tolerance(tolerance)
  {
  }

  virtual ~MixerOperationAddIf()
  {
  }

protected:
  /**
   * @copydoc IMixerOperation::doEvaluation
   */
  virtual cevalue_t doEvaluation(cevalue_t lastValue) const
  {
    cevalue_t in = getInputValue();
    cevalue_t halfTol = m_tolerance / 2.0;

    if ((in >= m_equalToValue - halfTol) && (in <= m_equalToValue + halfTol))
      return lastValue + m_weight;
    else
      return lastValue;
  }

private:
  const cevalue_t m_equalToValue;
  const cevalue_t m_tolerance;
};

#endif
