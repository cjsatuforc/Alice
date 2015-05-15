#ifndef ALICE_UIMANAGER_H
#define ALICE_UIMANAGER_H

#include "Types.h"
#include "Channel.h"

#include <U8glib.h>
#include <M2tk.h>

#define ALICE_MAX_MAIN_MENU_ELEMENTS 50

void ui_init(U8GLIB * glcd);
    
void ui_update();
void ui_handleButtonPress(uibutton_t id);
    
const char * ui_processChannelMenu(uint8_t idx, uint8_t msg);

#endif
