#include "ControlMapping.h"


ControlMapping::ControlMapping(inputid_t inputID,
                               channelid_t channelID,
                               controlmode_t mode) :
  m_inputID(inputID),
  m_channelID(channelID),
  m_mode(mode),
  m_setValue(0)
{
}


ControlMapping::ControlMapping(inputid_t inputID,
                               channelid_t channelID,
                               controlmode_t mode,
                               channelvalue_t value) :
  m_inputID(inputID),
  m_channelID(channelID),
  m_mode(mode),
  m_setValue(value)
{
}
