#include "SerialRadio.h"

SerialRadio::SerialRadio(Stream &port) : IRadio(),
  m_open(false), m_paired(false), m_port(port)
{
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
  char buffer[21];
  snprintf(buffer,21, "RADIO:CH:%d:%d", id, value);
  m_port.println(buffer);
  return true;
}

bool SerialRadio::tx()
{
  return true;
}
