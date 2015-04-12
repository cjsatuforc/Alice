#ifndef ALICE_UIMANAGER_H
#define ALICE_UIMANAGER_H

#include "Types.h"
#include "IChannel.h"

#include <U8glib.h>
#include <M2tk.h>

void ui_init(U8GLIB * glcd);
    
void ui_update();
void ui_handleButtonPress(uibutton_t id);
    
const char * ui_processChannelMenu(uint8_t idx, uint8_t msg);

#endif
