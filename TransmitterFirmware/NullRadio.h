#ifndef ALICE_NULLRADIO_H
#define ALICE_NULLRADIO_H

#include "IRadio.h"

class NullRadio : public IRadio
{
public:
  NullRadio()
      : IRadio()
  {
  }

  virtual bool open() { return true; }
  virtual bool close() { return true; }
  virtual bool isOpen() { return true; }
  virtual bool pair() { return true; }
  virtual bool unpair() { return true; }
  virtual bool isPaired() { return true; }

  virtual bool setChannel(channelid_t id, channelvalue_t value) { return true; }

  virtual bool tx() { return true; }
};

#endif
