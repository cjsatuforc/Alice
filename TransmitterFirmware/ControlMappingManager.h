#ifndef ALICE_CONTROLMAPPINGMANAGER_H
#define ALICE_CONTROLMAPPINGMANAGER_H

#include <IInputDevice.h>
#include "ControlMappingManager.h"
#include "ControlMapping.h"

class ControlMappingManager
{
public:
  static ControlMappingManager &Instance()
  {
    static ControlMappingManager instance;
    return instance;
  }

  static const int MAX_MAPPINGS = 50;

  bool handleInput(inputtype_t type, IInputDevice *device);

  bool addMapping(ControlMapping *mapping);

  int numMappings() { return m_numMappings; }

private:
  ControlMappingManager();

  ControlMappingManager(ControlMappingManager const &);
  void operator=(ControlMappingManager const &);

  int m_numMappings;
  ControlMapping *m_mappings[MAX_MAPPINGS];
};

#endif
