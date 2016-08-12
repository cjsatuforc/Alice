/** @file */

#ifndef _ALICE_MIXERCHANNEL_H_
#define _ALICE_MIXERCHANNEL_H_

#include "AliceObject.h"
#include "AliceObjectList.h"
#include "IMixerOperation.h"

/**
 * @class MixerChannel
 * @brief Represents a channel in a Mixer.
 */
class MixerChannel : public AliceObject
{
public:
  MixerChannel(char *name, size_t numOperations, cevalue_t initialValue = 0.0);
  virtual ~MixerChannel();

  usvalue_t initialValue() const;

  bool addOperation(IMixerOperation *item);
  IMixerOperation *getOperation(const char *name);
  size_t numOperations() const;

  cevalue_t evaluate() const;

private:
  const cevalue_t m_initialValue;
  AliceObjectList m_operations;
};

#endif
