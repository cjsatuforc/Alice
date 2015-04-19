#include "ChannelManager.h"


ChannelManager::ChannelManager()
{
  for(int i = 0; i < MAX_CHANNELS; i++)
    m_channels[i] = NULL;
}


bool ChannelManager::addChannel(Channel * channel)
{
  if(channel == NULL)
    return false;
    
  if(m_numChannels == MAX_CHANNELS)
    return false;
    
  m_channels[m_numChannels] = channel;
  m_numChannels++;
  return true;
}


Channel * ChannelManager::getChannel(int index)
{
  if(index >= m_numChannels)
    return NULL;
  
  return m_channels[index];
}


bool ChannelManager::sendToRadio(IRadio & radio)
{
  if(!(radio.isOpen() && radio.isPaired()))
    return false;
  
  for(int i = 0; i < m_numChannels; i++)
  {
    Channel * channel = getChannel(i);
    radio.setChannel(channel->getID(), channel->getValue());
  }
  
  return radio.tx();
}
