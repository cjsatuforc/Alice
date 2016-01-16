#ifndef _ALICE_MODEL_H_
#define _ALICE_MODEL_H_

#include "AliceTypes.h"
#include "AliceObject.h"
#include "Mixer.h"
#include "IOutput.h"

class Model : public AliceObject
{
  public:
    Model(char * name, size_t numOutputs);
    virtual ~Model();

    Mixer * getMixer();
    IOutput * getOutput(size_t n);
    size_t getNumberOutputs();

  private:
    Mixer *m_mixer;
    IOutput **m_outputs;
    size_t m_numOutputs;
};

#endif
