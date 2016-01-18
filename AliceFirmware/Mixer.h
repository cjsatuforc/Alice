/** @file */

#ifndef _ALICE_MIXER_H_
#define _ALICE_MIXER_H_

#include "AliceTypes.h"
#include "AliceObject.h"
#include "AliceObjectList.h"
#include "MixerChannel.h"

/**
 * @class Mixer
 * @brief A channel mixer that takes values from IInput devices and produces
 *        outputs for IOutput devcies.
 */
class Mixer : public AliceObject
{
  public:
    /**
     * @typedef MixerChannelNumber
     * @param Number given to a Mixer channel.
     */
    typedef size_t MixerChannelNumber;

    Mixer(char * name, size_t numChannels);
    virtual ~Mixer();

    bool addChannel(MixerChannelNumber idx, MixerChannel * item);
    MixerChannel * getChannel(MixerChannelNumber idx);

  private:
    AliceObjectList m_channels; //!< Mixer channels
};

#endif
