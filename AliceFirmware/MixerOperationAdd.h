/** @file */

#ifndef _ALICE_MIXEROPERATIONADD_H_
#define _ALICE_MIXEROPERATIONADD_H_

#include "IMixerOperation.h"

/**
 * @class MixerOperationAdd
 * @brief Mixer operation for input addition.
 *
 * Adds the value of the mapped input, scaled by the weight, to the last input
 * value.
 *
 * \f[
 *  new = old + \frac{weight * input}{100}
 * \f]
 */
class MixerOperationAdd : public IMixerOperation
{
  public:
    /**
     * @copydoc IMixerOperation::IMixerOperation
     */
    MixerOperationAdd(char * name, char * mappedInputName, cevalue_t weight)
      : IMixerOperation(name, mappedInputName, weight)
    {
    }

    virtual ~MixerOperationAdd() {}

  protected:
    /**
     * @copydoc IMixerOperation::doEvaluation
     */
    virtual cevalue_t doEvaluation(cevalue_t lastValue) const
    {
      return lastValue + (m_weight * getInputValue()) / 100.0;
    }
};

#endif
