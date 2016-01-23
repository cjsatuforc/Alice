/** @file */

#ifndef _ALICE_SDUTILS_H_
#define _ALICE_SDUTILS_H_

#include <SdFat.h>

/**
 * @class SDUtils
 * @brief Utility class for reading SD card.
 */
class SDUtils
{
public:
  SDUtils(uint8_t chipSelect = 10);
  virtual ~SDUtils();

  size_t directoryCount(const char *dir);
  size_t listDirectory(const char *dir, char *out, size_t len);

  size_t listConfigurations(const char *file, char *out, size_t len);
  size_t getConfigValue(const char *file, const char *key, char *out, size_t len);

private:
  SdFat m_sd;
};

#endif
