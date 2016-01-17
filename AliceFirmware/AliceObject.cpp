/** @file */

#include "AliceObject.h"

/**
 * @brief Constructs a new radio object.
 * @param name Name of the object
 */
AliceObject::AliceObject(char * name)
  : m_name(name)
{
}

AliceObject::~AliceObject()
{
}

/**
 * @brief Gets the name of the object
 * @return Name
 */
const char * AliceObject::getName() const
{
  return m_name;
}
