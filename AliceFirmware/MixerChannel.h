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
    MixerChannel(char * name, size_t numOperations, cevalue_t initialValue);
    virtual ~MixerChannel();

    bool addOperation(IMixerOperation * item);
    IMixerOperation * getOperation(const char * name);

    cevalue_t evaluate() const;

  private:
    const cevalue_t m_initialValue;
    AliceObjectList m_operations;
};

#endif
