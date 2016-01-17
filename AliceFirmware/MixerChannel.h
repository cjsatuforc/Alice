/** @file */

#ifndef _ALICE_MIXERCHANNEL_H_
#define _ALICE_MIXERCHANNEL_H_

#include "AliceObject.h"

class MixerChannel : public AliceObject
{
  public:
    MixerChannel(char * name);
    virtual ~MixerChannel();
};

#endif
