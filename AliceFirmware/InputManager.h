/** @file */

#ifndef _ALICE_INPUTMANAGER_H_
#define _ALICE_INPUTMANAGER_H_

/**
 * @def MAX_NUM_INPUTS
 * @brief Maximum number of IInput devices that can be added to the
 *        InputManager.
 */
#define MAX_NUM_INPUTS 16

#include "AliceObjectList.h"
#include "IInput.h"

/**
 * @class InputManager
 * @brief Manages input devices.
 */
class InputManager
{
public:
  /**
   * \brief Returns the instance of the input manager
   * \return InputManager instance
   */
  static InputManager &Instance()
  {
    static InputManager instance;
    return instance;
  }

  bool addInput(IInput *item);
  IInput *getInput(const char *name);

  void poll();

private:
  InputManager();
  InputManager(InputManager const &);
  void operator=(InputManager const &);

  AliceObjectList m_inputs;
};

#endif
