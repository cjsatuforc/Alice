#ifndef ALICE_CONTROLMAPPING_H
#define ALICE_CONTROLMAPPING_H

#include <UniversalInputTypes.h>

#include "Types.h"


class ControlMapping
{
  public:
    ControlMapping(inputtype_t inputType,
                   uint16_t inputID, channelid_t channelID,
                   controlmode_t mode);
    ControlMapping(inputtype_t inputType,
                   uint16_t inputID, channelid_t channelID,
                   controlmode_t mode, channelvalue_t value);

    inputtype_t getInputType() { return m_inputType; }
    uint16_t getInputID() { return m_inputID; }
    channelid_t getChannelID() { return m_channelID; }
    controlmode_t getMode() { return m_mode; }
    channelvalue_t getSetValue() { return m_setValue; }

  private:
    inputtype_t m_inputType;
    uint16_t m_inputID;
    channelid_t m_channelID;
    controlmode_t m_mode;
    channelvalue_t m_setValue;

};

#endif
