#ifndef _ALICE_ALICEOBJECT_H_
#define _ALICE_ALICEOBJECT_H_

#include "AliceTypes.h"

class AliceObject
{
  public:
    AliceObject(char * name);
    virtual ~AliceObject();

    char * getName();

  private:
    char * m_name;
};

#endif
