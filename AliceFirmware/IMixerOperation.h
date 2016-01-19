/** @file */

#ifndef _ALICE_IMIXEROPERATION_H_
#define _ALICE_IMIXEROPERATION_H_

#include "AliceTypes.h"
#include "AliceObject.h"

/**
 * @class IMixerOperation
 * @brief Represents an operation in a mixer channel
 */
class IMixerOperation : public AliceObject
{
public:
  IMixerOperation(char *name, char *mappedInputName, cevalue_t weight);
  virtual ~IMixerOperation();

  const char *getMappedInputName() const;

  cevalue_t getInputValue() const;
  cevalue_t evaluate(cevalue_t lastValue) const;

  cevalue_t getWeight() const;

protected:
  /**
   * @brief Performs calculation for mixing operation.
   * @param lastValue Current mix channel value
   * @return New mix channel value
   */
  virtual cevalue_t doEvaluation(cevalue_t lastValue) const = 0;

  const cevalue_t m_weight; //!< Weight associated with this mapping

private:
  const char *m_mappedInputName; //!< Name of mapped input device
};

#endif
