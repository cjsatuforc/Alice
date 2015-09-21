#ifndef ALICE_CHANNELMANAGER_H
#define ALICE_CHANNELMANAGER_H

#include "Channel.h"
#include "IRadio.h"

class ChannelManager
{
public:
  static ChannelManager &Instance()
  {
    static ChannelManager instance;
    return instance;
  }

  static const int MAX_CHANNELS = 12;

  int numChannels() { return m_numChannels; }

  bool addChannel(Channel *channel);
  Channel *getChannel(int index);

  bool sendToRadio(IRadio &radio);

private:
  ChannelManager();

  ChannelManager(ChannelManager const &);
  void operator=(ChannelManager const &);

  int m_numChannels;
  Channel *m_channels[MAX_CHANNELS];
};

#endif
