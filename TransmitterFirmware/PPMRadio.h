#ifndef PPM_RADIO_H
#define PPM_RADIO_H

#include "IRadio.h"

class PPMRadio : public IRadio
{
public:
  PPMRadio(int pin, size_t numChannels);

  virtual bool open() { return true; }
  virtual bool close() { return false; }
  virtual bool isOpen() { return true; }

  virtual bool pair() { return true; }
  virtual bool unpair() { return false; }
  virtual bool isPaired() { return true; }

  virtual bool setChannel(channelid_t id, channelvalue_t value);
  virtual bool tx() { return true; }

};

#endif
