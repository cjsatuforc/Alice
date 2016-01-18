/** @file */

#include "Model.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param numOutputs Number of output devices
 */
Model::Model(char * name, size_t numOutputs)
  : AliceObject(name)
  , m_mixer(NULL)
  , m_outputs(numOutputs)
{
}

Model::~Model()
{
}

/**
 * @brief Gets the active Mixer.
 * @return Pointer to the Mixer
 */
Mixer * Model::getMixer()
{
  return m_mixer;
}

/**
 * @copydoc AliceObjectList::add
 */
bool Model::addOutput(IOutput * item)
{
  return m_outputs.add(item);
}

/**
 * @copydoc AliceObjectList::getByName
 */
IOutput * Model::getOutput(const char * name)
{
  return (IOutput *) m_outputs.getByName(name);
}
