#ifndef ALICE_DEBUGRADIO_H
#define ALICE_DEBUGRADIO_H

#include "IRadio.h"

class DebugRadio : public IRadio
{
public:
  DebugRadio();

  virtual bool open();
  virtual bool close();
  virtual bool isOpen() { return m_open; }

  virtual bool pair();
  virtual bool unpair();
  virtual bool isPaired() { return m_paired; }

  virtual bool setChannel(channelid_t id, channelvalue_t value);
  virtual bool tx();

private:
  bool m_open;
  bool m_paired;

};

#endif
