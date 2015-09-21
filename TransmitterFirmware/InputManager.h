#ifndef ALICE_INPUTMANAGER_H
#define ALICE_INPUTMANAGER_H

#include <UniversalInputManager.h>

#include "Types.h"

class InputManager
{
public:
  static InputManager &Instance()
  {
    static InputManager instance;
    return instance;
  }

  bool poll(bool controlsOnly = false);

  bool addControl(IInputDevice *device);

private:
  InputManager();

  InputManager(InputManager const &);
  void operator=(InputManager const &);

  UniversalInputManager m_controls;
};

#endif
