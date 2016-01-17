/** @file */

#ifndef _ALICE_MIXER_H_
#define _ALICE_MIXER_H_

#include "AliceTypes.h"
#include "AliceObject.h"
#include "MixerChannel.h"

class Mixer : public AliceObject
{
  public:
    typedef size_t MixerChannelNumber;

    Mixer(char * name, size_t numChannels);
    virtual ~Mixer();

    MixerChannel * getChannel(MixerChannelNumber chan);

  private:
    MixerChannel **m_channels;
    size_t m_numChannels;
};

#endif
