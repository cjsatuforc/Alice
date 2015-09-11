#ifndef ALICE_TYPES_H
#define ALICE_TYPES_H

#include <Arduino.h>
#include <inttypes.h>


typedef uint8_t channelid_t;
typedef int16_t channelvalue_t;


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
