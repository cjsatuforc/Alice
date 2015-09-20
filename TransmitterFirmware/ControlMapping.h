#ifndef ALICE_CONTROLMAPPING_H
#define ALICE_CONTROLMAPPING_H

#include "UniversalInputTypes.h"
#include "Types.h"

class ControlMapping
{
  public:
    ControlMapping(inputid_t inputID,
                   channelid_t channelID,
                   controlmode_t mode);
    ControlMapping(inputid_t inputID,
                   channelid_t channelID,
                   controlmode_t mode,
                   channelvalue_t value);

    inputid_t getInputID() { return m_inputID; }
    channelid_t getChannelID() { return m_channelID; }
    controlmode_t getMode() { return m_mode; }
    channelvalue_t getSetValue() { return m_setValue; }

  private:
    inputid_t m_inputID;
    channelid_t m_channelID;
    controlmode_t m_mode;
    channelvalue_t m_setValue;

};

#endif
