#ifndef ALICE_ICHANNEL_H
#define ALICE_ICHANNEL_H

#include "Types.h"
#include <string>

//TODO: value set callback

class IChannel
{
public:
  typedef void (* channelcallback_t) (channelid_t, channelvalue_t);

  IChannel(std::string name,
           channelid_t id,
           channelvalue_t defaultValue,
           channelvalue_t max,
           channelvalue_t min,
           channelcallback_t callback = NULL);
  ~IChannel();

  std::string getName() { return m_name; }
  channelid_t getID() { return m_id; }

  channelvalue_t getValue() { return m_value; }
  channelvalue_t getMin() { return m_min; }
  channelvalue_t getMax() { return m_max; }

  bool setValue(channelvalue_t value);

private:
  std::string m_name;
  channelid_t m_id;
  channelcallback_t m_callback;
  channelvalue_t m_value;
  channelvalue_t m_min;
  channelvalue_t m_max;

};

#endif
