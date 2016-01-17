/** @file */

#include "Model.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param numOutputs Number of output devices
 */
Model::Model(char * name, size_t numOutputs)
  : AliceObject(name)
  , m_mixer(NULL)
  , m_numOutputs(numOutputs)
{
  m_outputs = new IOutput*[numOutputs];

  for (size_t i = 0; i < numOutputs; i++)
    m_outputs[i] = NULL;
}

Model::~Model()
{
  for (size_t i = 0; i < m_numOutputs; i++)
  {
    if (m_outputs[i] != NULL)
      delete m_outputs[i];
  }
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
 * @brief Gets an output device by name.
 * @param name Name of output device
 * @return Pointer to the IOutput, NULL if not found
 */
IOutput * Model::getOutput(const char * name)
{
  for (size_t i = 0; i < m_numOutputs; i++)
  {
    if (m_outputs[i] != NULL && strcmp(m_outputs[i]->getName(), name) == 0)
      return m_outputs[i];
  }

  return NULL;
}

/**
 * @brief Gets the number of output devices.
 * @return NUmber of outputs
 */
size_t Model::getNumberOutputs()
{
  return m_numOutputs;
}
