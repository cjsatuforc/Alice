/** @file */

#ifndef _ALICE_ALICEOBJECT_H_
#define _ALICE_ALICEOBJECT_H_

#include "AliceTypes.h"

/**
 * @class AliceObject
 * @brief Represents a component of the radio control structure.
 */
class AliceObject
{
  public:
    AliceObject(char * name);
    virtual ~AliceObject();

    const char * name() const;

  private:
    const char * m_name; //!< Name of the object
};

#endif
