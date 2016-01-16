#include "Mixer.h"

Mixer::Mixer(char * name, size_t numChannels)
  : AliceObject(name)
  , m_numChannels(numChannels)
{
  m_channels = new MixerChannel*[numChannels];

  for (size_t i = 0; i < m_numChannels; i++)
    m_channels[i] = NULL;
}

Mixer::~Mixer()
{
  for (size_t i = 0; i < m_numChannels; i++)
  {
    if (m_channels[i] != NULL)
      delete m_channels[i];
  }
}

MixerChannel * Mixer::getChannel(MixerChannelNumber chan)
{
  if (chan >= m_numChannels)
    return NULL;

  return m_channels[chan];
}
