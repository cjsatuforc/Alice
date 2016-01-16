#include "AliceObject.h"

AliceObject::AliceObject(char * name)
  : m_name(name)
{
}

AliceObject::~AliceObject()
{
}

char * AliceObject::getName()
{
  return m_name;
}
