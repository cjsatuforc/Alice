#ifndef ALICE_ICHANNEL_H
#define ALICE_ICHANNEL_H

#include "Types.h"


class Channel
{
public:
  typedef void (* channelcallback_t) (channelid_t, channelvalue_t);

  Channel(channelid_t id,
          char * name,
          channelvalue_t max = 1500,
          channelvalue_t min = 2500,
          channelcallback_t callback = NULL,
          channelvalue_t defaultValue = 0);
  ~Channel();

  char * getName() { return m_name; }
  channelid_t getID() { return m_id; }

  channelvalue_t getValue() { return m_value; }
  channelvalue_t getMin() { return m_min; }
  channelvalue_t getMax() { return m_max; }

  bool setValue(channelvalue_t value);

private:
  char * m_name;
  channelid_t m_id;
  channelcallback_t m_callback;
  channelvalue_t m_value;
  channelvalue_t m_min;
  channelvalue_t m_max;

};

#endif
