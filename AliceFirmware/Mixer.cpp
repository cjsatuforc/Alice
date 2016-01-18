/** @file */

#include "Mixer.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param numChannels Number of channels in the mixer
 */
Mixer::Mixer(char * name, size_t numChannels)
  : AliceObject(name)
  , m_channels(numChannels)
{
}

Mixer::~Mixer()
{
}

/**
 * @copydoc AliceObjectList::set
 */
bool Mixer::addChannel(MixerChannelNumber idx, MixerChannel * item)
{
  return m_channels.set(idx, item);
}

/**
 * @copydoc AliceObjectList::get
 */
MixerChannel * Mixer::getChannel(MixerChannelNumber idx)
{
  return (MixerChannel *) m_channels.get(idx);
}
