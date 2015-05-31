#ifndef PPM_RADIO_H
#define PPM_RADIO_H

#include "IRadio.h"

class PPMRadio : public IRadio
{
public:
  PPMRadio(int pin, size_t numChannels);

  virtual bool open();
  virtual bool close() { return false; }
  virtual bool isOpen() { return m_open; }

  virtual bool pair() { return true; }
  virtual bool unpair() { return false; }
  virtual bool isPaired() { return true; }

  virtual bool setChannel(channelid_t id, channelvalue_t value);
  virtual bool tx() { return true; }

  static void isr();

  static const long FRAME_LENGTH_MS = 22500;
  static const long PULSE_LENGTH_MS = 300;
  static const byte ON_STATE = 1;
  static const size_t MAX_CHANNELS = 16;

protected:
  static bool m_open;

  static int m_ppmPin;
  static size_t m_numChannels;

  static channelvalue_t m_channelVal[MAX_CHANNELS];

  static bool m_state;
  static byte m_currentChannelID;
  static unsigned int m_calcRest;

};

#endif
