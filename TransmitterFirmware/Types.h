#ifndef ALICE_TYPES_H
#define ALICE_TYPES_H

#include <Arduino.h>
#include <inttypes.h>

#include <M2tk.h>
#include <UniversalInput.h>

typedef uint8_t channelid_t;
typedef int16_t channelvalue_t;


/**
 * Button types and mapping to M2tk.
 */
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


/**
 * Used to define the type of control a physical input has over a channel.
 */
enum controlmode_t
{
  CONTROLMODE_SET,
  CONTROLMODE_SETVALUE,
  CONTROLMODE_TOGGLE
};


#endif
