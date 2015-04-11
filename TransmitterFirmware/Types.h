#ifndef ALICE_TYPES_H
#define ALICE_TYPES_H

#include <Arduino.h>
#include <inttypes.h>
#include <M2tk.h>


typedef uint8_t channelid_t;
typedef int16_t channelvalue_t;

enum uibutton_t
{
  BUTTON_SELECT = M2_KEY_SELECT,
  BUTTON_BACK = M2_KEY_EXIT,
  BUTTON_MENU = M2_KEY_HOME2,
  BUTTON_HOME = M2_KEY_HOME,
  BUTTON_UP = M2_KEY_PREV,
  BUTTON_DOWN = M2_KEY_NEXT,
  BUTTON_LEFT = M2_KEY_DATA_DOWN,
  BUTTON_RIGHT = M2_KEY_DATA_UP
};

#endif
