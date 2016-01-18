/** @file */

#include "AliceObjectList.h"

/**
 * @brief Creates a new container with a given capacity.
 * @param capacity Maximum number of elements
 */
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

/**
 * @brief Adds a new item to the list.
 * @param item Pointer to the item to add
 * @return True if instance was added to list, false if the list is full
 */
bool AliceObjectList::add(AliceObject * item)
{
  for (size_t i = 0; i < m_capacity; i++)
  {
    if (m_objects[i] == NULL)
    {
      m_objects[i] = item;
      return true;
    }
  }

  return false;
}

/**
 * @brief Adds a new item at a given position in the list.
 * @param idx Index at which item is inserted
 * @param item Pointer to the item to add
 * @return True if instance was added to list, false if the index is out of
 *         range
 */
bool AliceObjectList::set(size_t idx, AliceObject * item)
{
  if (idx >= m_capacity)
    return false;

  m_objects[idx] = item;
  return true;
}

/**
 * @brief Gets an item from the list by name.
 * @param name Name of item to get
 * @return Pointer to the item, NULL if not found
 */
AliceObject * AliceObjectList::getByName(const char * name) const
{
  for (size_t i = 0; i < m_capacity; i++)
  {
    if (m_objects[i] != NULL && strcmp(m_objects[i]->getName(), name) == 0)
      return m_objects[i];
  }

  return NULL;
}

/**
 * @brief Gets an item from the list by index.
 * @param idx Index of item to get
 * @return Pointer to the item, NULL if not found
 */
AliceObject * AliceObjectList::get(size_t idx) const
{
  if (idx >= m_capacity)
    return NULL;

  return m_objects[idx];
}

/**
 * @brief Returns the number of elements stored in the list.
 * @return Number of elements
 */
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

/**
 * @brief Returns the maximum number of elements that can be stored in the
 *        list.
 * @return Maximum number of elements
 */
size_t AliceObjectList::capacity() const
{
  return m_capacity;
}
