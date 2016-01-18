/** @file */

#include "MixerChannel.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param numOperations Number of operations in this channel
 * @param initialValue Initial value of the channel before operations are
 *                     evaluated
 */
MixerChannel::MixerChannel(char * name, size_t numOperations, cevalue_t initialValue)
  : AliceObject(name)
  , m_initialValue(initialValue)
  , m_operations(numOperations)
{
}

MixerChannel::~MixerChannel()
{
}

/**
 * @copydoc AliceObjectList::add
 */
bool MixerChannel::addOperation(IMixerOperation * item)
{
  return m_operations.add(item);
}

/**
 * @copydoc AliceObjectList::getByName
 */
IMixerOperation * MixerChannel::getOperation(const char * name)
{
  return (IMixerOperation *) m_operations.getByName(name);
}

/**
 * @brief Evaluates the mixer by evaluating each operation in turn in the order
 *        they were added.
 * @return Evaluated value
 */
cevalue_t MixerChannel::evaluate() const
{
  cevalue_t value = m_initialValue;

  // TODO

  return value;
}
