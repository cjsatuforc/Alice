#ifndef ALICE_TYPES_H
#define ALICE_TYPES_H

#include <Arduino.h>
#include <inttypes.h>
#include <M2tk.h>


typedef uint8_t channelid_t;
typedef int16_t channelvalue_t;

enum uibutton_t
{
  BUTTON_MENU_SELECT = M2_KEY_SELECT,
  BUTTON_CHANNELS = M2_KEY_Q1,
  BUTTON_MACROS = M2_KEY_Q2,
  BUTTON_EXIT = M2_KEY_EXIT,
  BUTTON_UP = M2_KEY_PREV,
  BUTTON_DOWN = M2_KEY_NEXT,
  BUTTON_LEFT = M2_KEY_DATA_DOWN,
  BUTTON_RIGHT = M2_KEY_DATA_UP
};

#endif
