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
bool Mixer::addChannel(channelnumber_t idx, MixerChannel * item)
{
  return m_channels.set(idx, item);
}

/**
 * @copydoc AliceObjectList::get
 */
MixerChannel * Mixer::getChannel(channelnumber_t idx)
{
  return (MixerChannel *) m_channels.get(idx);
}

/**
 * @brief Evaluates and returns the value of a MixerChannel given its channel
 *        number.
 * @param idx Channel number
 * @return Evaluated value, can also return 0.0 if channel was not found
 */
usvalue_t Mixer::evaluate(channelnumber_t idx)
{
  MixerChannel * chan = (MixerChannel *) m_channels.get(idx);

  if (chan == NULL)
    return 0.0;

  return chan->evaluate();
}
