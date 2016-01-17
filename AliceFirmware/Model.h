/** @file */

#ifndef _ALICE_MODEL_H_
#define _ALICE_MODEL_H_

#include "AliceTypes.h"
#include "AliceObject.h"
#include "Mixer.h"
#include "IOutput.h"

/**
 * @class Model
 * @brief Represents the configuration of a model.
 */
class Model : public AliceObject
{
  public:
    Model(char * name, size_t numOutputs);
    virtual ~Model();

    Mixer * getMixer();
    IOutput * getOutput(const char * name);
    size_t getNumberOutputs();

  private:
    Mixer *m_mixer; //!< Mixer used by the Model
    IOutput **m_outputs; //!< Output devices
    size_t m_numOutputs; //!< Number of output devices
};

#endif
