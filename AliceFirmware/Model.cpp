#include "Model.h"

#include <Arduino.h>

Model::Model()
  : m_mixer(NULL)
{
  for (size_t i = 0; i < MAX_NUM_OUTPUTS; i++)
    m_outputs[i] = NULL;
}

Model::~Model()
{
}
