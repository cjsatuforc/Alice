/** @file */

#include "Radio.h"

#include <Arduino.h>

/**
 * @brief Constructs the Radio.
 */
Radio::Radio()
    : m_inputs(MAX_NUM_INPUTS)
    , m_activeModel(NULL)
{
}

/**
 * @param Sets the active model and reinitialises the radio.
 * @param model New model
 * @return True for a successful reinitialisation
 */
bool Radio::setModel(Model *model)
{
  m_activeModel = model;
  return init();
}

/**
 * @brief Initialise the radio.
 * @return True for a successful initialisation
 */
bool Radio::init()
{
  bool retVal = true;

  for (size_t i = 0; i < m_activeModel->numOutputs(); i++)
  {
    if (!m_activeModel->getOutputByIndex(i)->open())
      retVal = false;
  }

  return retVal;
}

/**
 * @brief Processes a state update.
 */
void Radio::update()
{
  Mixer *mixer = m_activeModel->getMixer();

  size_t numChannels = mixer->numChannels();
  usvalue_t channelValues[numChannels];
  mixer->fillOutputArrayTiming(channelValues, numChannels);

  for (size_t i = 0; i < m_activeModel->numOutputs(); i++)
  {
    IOutput *out = m_activeModel->getOutputByIndex(i);
    out->setValues(channelValues, numChannels);
    out->tx();
  }
}

/**
 * @copydoc AliceObjectList::add
 */
bool Radio::addInput(IInput *item)
{
  return m_inputs.add(item);
}

/**
 * @copydoc AliceObjectList::getByName
 */
IInput *Radio::getInput(const char *name)
{
  return (IInput *)m_inputs.getByName(name);
}
