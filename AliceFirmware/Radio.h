/** @file */

#ifndef _ALICE_RADIO_H_
#define _ALICE_RADIO_H_

#include "Model.h"

/**
 * @class Radio
 * @brief Represents the entire radio and it's components.
 */
class Radio
{
public:
  /**
   * \brief Returns the instance of the radio
   * \return Radio instance
   */
  static Radio &Instance()
  {
    static Radio instance;
    return instance;
  }

private:
  Radio();
  Radio(Radio const &);
  void operator=(Radio const &);

  Model *m_activeModel; //!< Model that is currently loaded
};

#endif
