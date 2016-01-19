/** @file */

#ifndef _ALICE_ALICEOBJECTLIST_H_
#define _ALICE_ALICEOBJECTLIST_H_

#include "AliceObject.h"

/**
 * @class AliceObjectList
 * @brief Container for a list of AliceObject instances.
 */
class AliceObjectList
{
public:
  AliceObjectList(size_t capacity);
  virtual ~AliceObjectList();

  bool add(AliceObject *object);
  bool set(size_t idx, AliceObject *item);

  AliceObject *get(size_t idx) const;
  AliceObject *getByName(const char *name) const;

  size_t size() const;
  size_t capacity() const;

private:
  size_t m_capacity;       //!< Maximum number of instances that can be stored
  AliceObject **m_objects; //!< Pointer to arroy of AliceObject
};

#endif
