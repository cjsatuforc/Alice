#include "SerialRadio.h"

SerialRadio::SerialRadio(Stream &port, bool alwaysPrint)
    : IRadio()
    , m_open(false)
    , m_paired(false)
    , m_alwaysPrint(alwaysPrint)
    , m_port(port)
{
  memset(m_values, ChannelManager::MAX_CHANNELS, 0);
}

bool SerialRadio::open()
{
  m_port.println("RADIO:OPEN");
  m_open = true;
  return true;
}

bool SerialRadio::close()
{
  m_port.println("RADIO:CLOSE");
  m_open = false;
  return true;
}

bool SerialRadio::pair()
{
  m_port.println("RADIO:PAIR");
  m_paired = true;
  return true;
}

bool SerialRadio::unpair()
{
  m_port.println("RADIO:UNPAIR");
  m_paired = false;
  return true;
}

bool SerialRadio::setChannel(channelid_t id, channelvalue_t value)
{
  bool changed = m_values[id] != value;
  if (m_alwaysPrint || changed)
  {
    char buffer[21];
    snprintf(buffer, 21, "RADIO:CH:%d:%d", id, value);
    m_port.println(buffer);
    m_values[id] = value;
    return true;
  }
  else
    return false;
}

bool SerialRadio::tx()
{
  return true;
}
