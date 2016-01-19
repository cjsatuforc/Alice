/** @file */

#include "MixerChannel.h"

/**
 * @copydoc AliceObject::AliceObject
 * @param numOperations Number of operations in this channel
 * @param initialValue Initial value of the channel before operations are
 *                     evaluated
 */
MixerChannel::MixerChannel(char *name, size_t numOperations, cevalue_t initialValue)
    : AliceObject(name)
    , m_initialValue(initialValue)
    , m_operations(numOperations)
{
}

MixerChannel::~MixerChannel()
{
}

/**
 * @brief Gets the initial value of the channel before operations are applied.
 * @return Initial zero centred value
 */
usvalue_t MixerChannel::initialValue() const
{
  return m_initialValue;
}

/**
 * @copydoc AliceObjectList::add
 */
bool MixerChannel::addOperation(IMixerOperation *item)
{
  return m_operations.add(item);
}

/**
 * @copydoc AliceObjectList::getByName
 */
IMixerOperation *MixerChannel::getOperation(const char *name)
{
  return (IMixerOperation *)m_operations.getByName(name);
}

/**
 * @copydoc AliceObjectList::size
 */
size_t MixerChannel::numOperations() const
{
  return m_operations.size();
}

/**
 * @brief Evaluates the mixer by evaluating each operation in turn in the order
 *        they were added.
 * @return Evaluated value
 */
cevalue_t MixerChannel::evaluate() const
{
  cevalue_t value = m_initialValue;

  for (size_t i = 0; i < m_operations.size(); i++)
  {
    IMixerOperation *op = (IMixerOperation *)m_operations.get(i);
    value = op->evaluate(value);
  }

  return value;
}
