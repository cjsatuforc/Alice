/** @file */

#include "MixerChannel.h"

/**
 * @copydoc AliceObject::AliceObject
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

bool MixerChannel::addOperation(IMixerOperation *op)
{
  return m_operations.add(op);
}

IMixerOperation * MixerChannel::getOperation(const char * name)
{
  return (IMixerOperation *) m_operations.get(name);
}

cevalue_t MixerChannel::evaluate() const
{
  return 0.0;
}
