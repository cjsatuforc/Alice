/** @file */

#ifndef _ALICE_MIXEROPERATIONREPLACEIF_H_
#define _ALICE_MIXEROPERATIONREPLACEIF_H_

#include "IMixerOperation.h"

/**
 * @class MixerOperationReplaceIf
 * @brief Mixer operation for conditional replacement.
 *
 * If input value is equal to the equal parameter within tolerance then the
 * output value is set to the weight, otherwise the output is the input value
 * unchanged.
 */
class MixerOperationReplaceIf : public IMixerOperation
{
  public:
    /**
     * @copydoc IMixerOperation::IMixerOperation
     * @param equal Value to check input value comparison with
     * @param tolerance Tolerance to use when checking equality
     */
    MixerOperationReplaceIf(char * name, char * mappedInputName, cevalue_t weight, cevalue_t equal, cevalue_t tolerance = 5)
      : IMixerOperation(name, mappedInputName, weight)
      , m_equalToValue(equal)
      , m_tolerance(tolerance)
    {
    }

    virtual ~MixerOperationReplaceIf() {}

  protected:
    /**
     * @copydoc IMixerOperation::doEvaluation
     */
    virtual cevalue_t doEvaluation(cevalue_t lastValue) const
    {
      cevalue_t in = getInputValue();
      cevalue_t halfTol = m_tolerance / 2.0;

      if ((in >= m_equalToValue - halfTol) && (in <= m_equalToValue + halfTol))
        return m_weight;
      else
        return lastValue;
    }

  private:
    const cevalue_t m_equalToValue;
    const cevalue_t m_tolerance;
};

#endif
