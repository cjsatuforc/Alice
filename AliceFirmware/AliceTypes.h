/** @file */

#ifndef _ALICE_ALICETYPES_H_
#define _ALICE_ALICETYPES_H_

#include <Arduino.h>
#include <inttypes.h>

/**
 * @def US_LOW
 * @brief Minimum timing value.
 */
#define US_LOW 1000

/**
 * @def US_CENTRE
 * @brief Centre timing value.
 */
#define US_CENTRE 1500

/**
 * @def US_HIGH
 * @brief Maximum timing value.
 */
#define US_HIGH 2000

/**
 * @def CE_LOW
 * @brief Minimum zero centred value.
 */
#define CE_LOW -100.0

/**
 * @def CE_CENTRE
 * @brief Centre zero centred value.
 */
#define CE_CENTRE 0.0

/**
 * @def CE_HIGH
 * @brief Maximum zero centred value.
 */
#define CE_HIGH 100.0

/**
 * @typedef usvalue_t
 * @brief Used for timing values (in microseconds), 1000 to 2000.
 */
typedef int16_t usvalue_t;

/**
 * @typedef cevalue_t
 * @brief Used for zero centred values, -100 to 100.
 */
typedef double cevalue_t;

/**
 * @typedef channelnumber_t
 * @brief Used to represent a channel in a Mixer or IOutput device.
 */
typedef size_t channelnumber_t;

usvalue_t ce_to_us(cevalue_t value);

cevalue_t us_to_ce(usvalue_t value);

#endif
