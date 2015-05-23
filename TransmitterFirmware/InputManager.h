#ifndef ALICE_INPUTMANAGER_H
#define ALICE_INPUTMANAGER_H

#include <UniversalInputManager.h>

#include "Types.h"


class InputManager
{
  public:
    static InputManager& Instance()
    {
      static InputManager instance;
      return instance;
    }

    bool poll(bool ui = true, bool controls = true);

    bool addUIButton(uibutton_t id, inputpin_t pin);
    bool addControl(IInputDevice * device);

  private:
    InputManager();

    InputManager(InputManager const&);
    void operator=(InputManager const&);

    UniversalInputManager m_uiButtons;
    UniversalInputManager m_controls;

};

#endif
