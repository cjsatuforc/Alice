#ifndef ALICE_CHANNELMANAHER_H
#define ALICE_CHANNELMANAHER_H

#include "IChannel.h"
#include "IRadio.h"

class ChannelManager
{
  public:
    static ChannelManager& Instance()
    {
      static ChannelManager instance;
      return instance;
    }
    
    static const int MAX_CHANNELS = 12;
    
    bool addChannel(IChannel * channel);
    
    int numChannels() { return m_numChannels; }
    IChannel * getChannel(int index);
    
    bool sendToRadio(IRadio & radio);
    
  private:
    ChannelManager();
    
    ChannelManager(ChannelManager const&);
    void operator=(ChannelManager const&);
    
    int m_numChannels;
    IChannel *m_channels[MAX_CHANNELS];
    
};


#endif
