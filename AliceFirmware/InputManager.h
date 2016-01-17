/** @file */

#ifndef _ALICE_INPUTMANAGER_H_
#define _ALICE_INPUTMANAGER_H_

#define MAX_NUM_INPUTS 16

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

    void poll();
    bool addInput(IInput * input);
    IInput * getInput(const char * inputName);

  private:
    InputManager();
    InputManager(InputManager const &);
    void operator=(InputManager const &);

    IInput *m_inputs[MAX_NUM_INPUTS]; //!< Array of input devices
};

#endif
