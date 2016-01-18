/** @file */

#ifndef _ALICETESTS_ALICETEST_H_
#define _ALICETESTS_ALICETEST_H_

/**
 * @def assertClose
 * @brief Used to test that two doubles are equal within a tolerance of 0.01.
 */
#define assertClose(a, b) assertTrue(abs(a - b) < 0.01)

#endif
