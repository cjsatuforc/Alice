#include "ControlMapping.h"

ControlMapping::ControlMapping(inputtype_t inputType,
                               uint16_t inputID, channelid_t channelID,
                               controlmode_t mode) :
  m_inputType(inputType), m_inputID(inputID), m_channelID(channelID),
  m_mode(mode), m_setValue(0)
{
}

ControlMapping::ControlMapping(inputtype_t inputType,
                               uint16_t inputID, channelid_t channelID,
                               controlmode_t mode, channelvalue_t value) :
  m_inputType(inputType), m_inputID(inputID), m_channelID(channelID),
  m_mode(mode), m_setValue(value)
{
}
