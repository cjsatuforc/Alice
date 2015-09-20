#ifndef ALICE_SERIALRADIO_H
#define ALICE_SERIALRADIO_H

#include "IRadio.h"
#include <Stream.h>

class SerialRadio : public IRadio
{
public:
  SerialRadio(Stream &port);

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
  Stream &m_port;

};

#endif
