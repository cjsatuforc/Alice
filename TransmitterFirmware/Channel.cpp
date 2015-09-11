#include "Channel.h"


Channel::Channel(channelid_t id,
                 char * name,
                 channelvalue_t max,
                 channelvalue_t min,
                 channelcallback_t callback,
                 channelvalue_t defaultValue) :
  m_id(id),
  m_name(name),
  m_min(min),
  m_max(max),
  m_callback(callback)
{
  if(m_min > m_max)
  {
    channelvalue_t temp = m_min;
    m_min = m_max;
    m_max = temp;
  }

  if(defaultValue >= m_min && defaultValue <= m_max)
    m_value = defaultValue;
  else
    m_value = m_min;
}


Channel::~Channel()
{
}


bool Channel::setValue(channelvalue_t value)
{
  if(value >= m_min && value <= m_max)
  {
    m_value = value;

    if(m_callback)
      (*m_callback)(m_id, m_value);

    return true;
  }

  return false;
}
