/** @file */

#ifndef _ALICE_MODEL_H_
#define _ALICE_MODEL_H_

#include "AliceTypes.h"
#include "AliceObject.h"
#include "AliceObjectList.h"
#include "Mixer.h"
#include "IOutput.h"

/**
 * @class Model
 * @brief Represents the configuration of a model.
 */
class Model : public AliceObject
{
public:
  Model(char *name, size_t numOutputs);
  virtual ~Model();

  Mixer *getMixer();

  bool addOutput(IOutput *item);
  IOutput *getOutput(const char *name);

private:
  Mixer *m_mixer;            //!< Mixer used by the Model
  AliceObjectList m_outputs; //!< Output devices
};

#endif
