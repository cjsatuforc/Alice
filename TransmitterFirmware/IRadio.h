#ifndef ALICE_IRADIO_H
#define ALICE_IRADIO_H

#include "Types.h"

class IRadio
{
public:
  IRadio();
  ~IRadio();

  virtual bool open() = 0;
  virtual bool close() = 0;
  virtual bool isOpen() = 0;

  virtual bool pair() = 0;
  virtual bool unpair() = 0;
  virtual bool isPaired() = 0;

  virtual bool setChannel(channelid_t id, channelvalue_t value) = 0;
  virtual bool tx() = 0;

  virtual std::vector<std::string> getOptionNames() = 0;
  virtual bool setOption(std::string name, int16_t value) = 0;

};

#endif
