#include "DebugRadio.h"

#include "SerialLog.h"


DebugRadio::DebugRadio() : IRadio(),
  m_open(false), m_paired(false)
{
  info("DebugRadio Created");
}


bool DebugRadio::open()
{
  info("DebugRadio Opened");
  m_open = true;
  return true;
}


bool DebugRadio::close()
{
  info("DebugRadio Closed");
  m_open = false;
  return true;
}


bool DebugRadio::pair()
{
  info("DebugRadio Paired");
  m_paired = true;
  return true;
}


bool DebugRadio::unpair()
{
  info("DebugRadio Unpaired");
  m_paired = false;
  return true;
}


bool DebugRadio::setChannel(channelid_t id, channelvalue_t value)
{
  info("DebugRadio Set Channel");
  
  //TODO
  Serial.println(id);
  Serial.println(value);
  
  return true;
}


bool DebugRadio::tx()
{
  info("DebugRadio Tx");
  return true;
}
