/*! \file */

#include "Model.h"

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

Mixer * Model::getMixer()
{
  return m_mixer;
}

IOutput * Model::getOutput(size_t n)
{
  if (n >= m_numOutputs)
    return NULL;

  return m_outputs[n];
}

size_t Model::getNumberOutputs()
{
  return m_numOutputs;
}
