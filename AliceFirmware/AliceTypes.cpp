/** @file */

#include "AliceTypes.h"

/**
 * @var CE_TO_US_FACT
 * @brief Factor for converting from zero centred values to timing values.
 */
const double CE_TO_US_FACT = (US_HIGH - US_LOW) / (CE_HIGH - CE_LOW);

/**
 * @var US_TO_CE_FACT
 * @brief Factor for converting from timing values to zero centred values.
 */
const double US_TO_CE_FACT = (CE_HIGH - CE_LOW) / (US_HIGH - US_LOW);

/**
 * @brief Converts a zero centred value to a timing value.
 * @param value Zero centred value
 * @return Timing value
 */
usvalue_t ce_to_us(cevalue_t value)
{
  return (value - CE_LOW) * CE_TO_US_FACT + US_LOW;
}

/**
 * @brief Converts a timing value to a zero centred value.
 * @param value Timing value
 * @return Zero centred value
 */
usvalue_t us_to_ce(cevalue_t value)
{
  return (value - US_LOW) * US_TO_CE_FACT + CE_LOW;
}
