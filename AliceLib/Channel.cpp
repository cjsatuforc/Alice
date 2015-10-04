#include "Channel.h"

Channel::Channel(channelid_t id, char *name, channelvalue_t max,
                 channelvalue_t min, channelvalue_t centre, bool reverse,
                 channelvalue_t trim)
    : m_id(id)
    , m_name(name)
    , m_min(min)
    , m_max(max)
    , m_centre(centre)
    , m_reverse(reverse)
    , m_trim(trim)
{
  if (m_min > m_max)
  {
    channelvalue_t temp = m_min;
    m_min = m_max;
    m_max = temp;
  }

  if (m_centre > m_max || m_centre < m_min)
    m_centre = m_min + ((m_max + m_min) / 2);

  m_rawValue = m_centre;
}

Channel::~Channel()
{
}

channelvalue_t Channel::getValue()
{
  channelvalue_t value = m_rawValue;

  value += m_trim;

  if (value < m_min)
    value = m_min;
  else if (value > m_max)
    value = m_max;

  if (m_reverse)
  {
    channelvalue_t delta = m_centre - value;
    value = m_centre + delta;
  }

  return value;
}

void Channel::setRawValue(channelvalue_t value)
{
  m_rawValue = value;
}

bool Channel::setMin(channelvalue_t value)
{
  if (value >= m_centre)
    return false;

  m_min = value;
  return true;
}

bool Channel::setCentre(channelvalue_t value)
{
  if (value >= m_max || value <= m_min)
    return false;

  m_centre = value;
  return true;
}

bool Channel::setMax(channelvalue_t value)
{
  if (value <= m_centre)
    return false;

  m_max = value;
  return true;
}

void Channel::setReverse(bool reverse)
{
  m_reverse = reverse;
}

void Channel::setTrim(channelvalue_t value)
{
  m_trim = value;
}
