#include "ChannelManager.h"


bool ChannelManager::addChannel(IChannel * channel)
{
  if(channel == NULL)
    return false;
    
  if(m_numChannels == MAX_CHANNELS)
    return false;
    
  m_channels[m_numChannels] = channel;
  m_numChannels++;
  return true;
}


IChannel * ChannelManager::getChannel(int index)
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
    IChannel * channel = getChannel(i);
    radio.setChannel(channel->getID(), channel->getValue());
  }
  
  return radio.tx();
}
