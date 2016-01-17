/*! \file */

#include "AliceObject.h"

AliceObject::AliceObject(char * name)
  : m_name(name)
{
}

AliceObject::~AliceObject()
{
}

const char * AliceObject::getName() const
{
  return m_name;
}
