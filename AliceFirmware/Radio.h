/** @file */

#ifndef _ALICE_RADIO_H_
#define _ALICE_RADIO_H_

#include "AliceObjectList.h"
#include "IInput.h"
#include "Model.h"

/**
 * @def MAX_NUM_INPUTS
 * @brief Maximum number of inputs that can be registered.
 */
#define MAX_NUM_INPUTS 16

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

  bool addInput(IInput *item);
  IInput *getInput(const char *name);

  bool init();

  void update();

private:
  Radio();
  Radio(Radio const &);
  void operator=(Radio const &);

  AliceObjectList m_inputs; //!< Physical inputs
  Model *m_activeModel; //!< Model that is currently loaded
};

#endif
