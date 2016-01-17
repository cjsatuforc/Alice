/** @file */

#ifndef _ALICE_ALICEOBJECTLIST_H_
#define _ALICE_ALICEOBJECTLIST_H_

#include "AliceObject.h"

/**
 * @class AliceObjectList
 * @brief Represents a component of the radio control structure.
 */
class AliceObjectList
{
  public:
    AliceObjectList(size_t capacity);
    virtual ~AliceObjectList();

    bool add(AliceObject * object);
    AliceObject * get(const char * name) const;

    size_t size() const;
    size_t capacity() const;

  private:
    size_t m_capacity;
    AliceObject **m_objects;
};

#endif
