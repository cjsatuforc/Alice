#ifndef _ALICE_MODEL_H_
#define _ALICE_MODEL_H_

#define MAX_NUM_OUTPUTS 2

#include "Mixer.h"
#include "IOutput.h"

class Model
{
  public:
    Model();
    virtual ~Model();

  private:
    Mixer *m_mixer;
    IOutput *m_outputs[MAX_NUM_OUTPUTS];
};

#endif
