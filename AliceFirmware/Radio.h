/*! \file */

#ifndef _ALICE_RADIO_H_
#define _ALICE_RADIO_H_

#include "Model.h"

class Radio
{
  public:
    static Radio &Instance()
    {
      static Radio instance;
      return instance;
    }

  private:
    Radio();
    Radio(Radio const &);
    void operator=(Radio const &);

    Model *m_activeModel;
};

#endif
