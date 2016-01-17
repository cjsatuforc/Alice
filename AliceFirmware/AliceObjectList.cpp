/** @file */

#include "AliceObjectList.h"

AliceObjectList::AliceObjectList(size_t capacity)
  : m_capacity(capacity)
{
  m_objects = new AliceObject*[capacity];

  for (size_t i = 0; i < m_capacity; i++)
    m_objects[i] = NULL;
}

AliceObjectList::~AliceObjectList()
{
  for (size_t i = 0; i < m_capacity; i++)
  {
    if (m_objects[i] != NULL)
      delete m_objects[i];
  }
}

bool AliceObjectList::add(AliceObject * object)
{
  for (size_t i = 0; i < m_capacity; i++)
  {
    if (m_objects[i] == NULL)
    {
      m_objects[i] = object;
      return true;
    }
  }

  return false;
}

AliceObject * AliceObjectList::get(const char * name) const
{
  for (size_t i = 0; i < m_capacity; i++)
  {
    if (m_objects[i] != NULL && strcmp(m_objects[i]->getName(), name) == 0)
      return m_objects[i];
  }

  return NULL;
}

size_t AliceObjectList::size() const
{
  size_t s = 0;

  for (size_t i = 0; i < m_capacity; i++)
  {
    if (m_objects[i] != NULL)
      s++;
  }

  return s;
}

size_t AliceObjectList::capacity() const
{
  return m_capacity;
}
