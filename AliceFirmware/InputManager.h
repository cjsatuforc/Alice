#ifndef _ALICE_INPUTMANAGER_H_
#define _ALICE_INPUTMANAGER_H_

#define MAX_NUM_INPUTS 16

#include "IInput.h"

class InputManager
{
  public:
    static InputManager &Instance()
    {
      static InputManager instance;
      return instance;
    }

  private:
    InputManager();
    InputManager(InputManager const &);
    void operator=(InputManager const &);

    IInput *m_inputs[MAX_NUM_INPUTS];
};

#endif
