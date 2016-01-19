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
 * @brief Initialise the radio.
 * @return True for a successful initialisation
 */
bool Radio::init()
{
  // TODO
  return false;
}

/**
 * @brief Processes a state update.
 */
void Radio::update()
{
  // TODO
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
