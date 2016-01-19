/** @file */

#include "Mixer.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param numChannels Number of channels in the mixer
 */
Mixer::Mixer(char *name, size_t numChannels)
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
bool Mixer::addChannel(channelnumber_t idx, MixerChannel *item)
{
  return m_channels.set(idx, item);
}

/**
 * @copydoc AliceObjectList::get
 */
MixerChannel *Mixer::getChannel(channelnumber_t idx)
{
  return (MixerChannel *)m_channels.get(idx);
}

/**
 * @brief Evaluates and returns the value of a MixerChannel given its channel
 *        number.
 * @param idx Channel number
 * @return Evaluated value, can also return 0.0 if channel was not found
 */
cevalue_t Mixer::evaluate(channelnumber_t idx) const
{
  MixerChannel *chan = (MixerChannel *)m_channels.get(idx);

  if (chan == NULL)
    return 0.0;

  return chan->evaluate();
}

/**
 * @brief Fills an array with evealuated values from each channel of the mixer.
 * @param output Pointer to output array
 * @param len Length of output array
 * @return Number of valid elements in outout array
 */
size_t Mixer::fillOutputArray(cevalue_t *output, size_t len) const
{
  size_t i;

  for (i = 0; i < len; i++)
  {
    if (i >= m_channels.size())
      break;

    output[i] = evaluate(i);
  }

  return i;
}
