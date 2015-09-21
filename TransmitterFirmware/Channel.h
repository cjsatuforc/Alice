#ifndef ALICE_ICHANNEL_H
#define ALICE_ICHANNEL_H

#include "Types.h"

class Channel
{
public:
  Channel(channelid_t id, char *name, channelvalue_t max = 1000,
          channelvalue_t min = 2000, channelvalue_t centre = 1500,
          bool reverse = false, channelvalue_t trim = 0);
  ~Channel();

  char *getName() { return m_name; }
  channelid_t getID() { return m_id; }

  channelvalue_t getValue();

  channelvalue_t getRawValue() { return m_rawValue; }
  void setRawValue(channelvalue_t value);

  channelvalue_t getMin() { return m_min; }
  channelvalue_t getCentre() { return m_centre; }
  channelvalue_t getMax() { return m_max; }
  bool isReversed() { return m_reverse; }
  channelvalue_t getTrim() { return m_trim; }

private:
  char *m_name;
  channelid_t m_id;
  channelvalue_t m_rawValue;

  channelvalue_t m_min;
  channelvalue_t m_centre;
  channelvalue_t m_max;

  bool m_reverse;
  channelvalue_t m_trim;
};

#endif
