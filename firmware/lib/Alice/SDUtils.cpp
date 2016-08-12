#include "SDUtils.h"

/**
 * @brief Creates a new SD utility driver.
 * @param chipSelect Chip select pin (default 10)
 */
SDUtils::SDUtils(uint8_t chipSelect)
    : m_sd()
{
  m_sd.begin(chipSelect, SPI_HALF_SPEED);
}

SDUtils::~SDUtils()
{
}

/**
 * @brief Counts the number of regular files in a directory.
 * @param dir Name of directory
 * @return Number of files in directory
 */
size_t SDUtils::directoryCount(const char *dir)
{
  SdFile file;

  if (!m_sd.chdir(dir))
    return 0;

  size_t count = 0;

  while (file.openNext(m_sd.vwd(), O_READ))
  {
    if (file.isFile())
      count++;

    file.close();
  }

  return count;
}

/**
 * @brief Generates a comma separated list of all file names in a directory.
 * @param dir Name of the directory
 * @param out Array to store output in
 * @param len Length of output array
 * @return Number of bytes in output string
 */
size_t SDUtils::listDirectory(const char *dir, char *out, size_t len)
{
  SdFile file;

  if (!m_sd.chdir(dir))
    return 0;

  char *p = out;
  char *end = (out + len);

  while (file.openNext(m_sd.vwd(), O_READ))
  {
    if (file.isFile())
    {
      file.getName(p, end - p);
      p += strlen(p);
      *(p++) = ',';
    }

    file.close();
  }

  *(--p) = '\0';

  return p - out;
}

/**
 * @brief Genertes a comma seperated list of config keys in a given file.
 * @param file File to parse
 * @param out Array to store output in
 * @param len Length of output array
 * @return Number of bytes in output string
 */
size_t SDUtils::listConfigurations(const char *file, char *out, size_t len)
{
  ifstream inFile(file);

  char *p = out;
  char buffer[100];
  while (inFile.getline(buffer, 100, '\n') || inFile.gcount())
  {
    // Skip empty lines
    if (strlen(buffer) == 0)
      continue;

    // Split to get key
    char *k = strtok(buffer, "=");

    strcpy(p, k);
    p += strlen(k);
    *(p++) = ',';
  }

  *(--p) = '\0';

  return p - out;
}

/**
 * @brief Gets the value of a given config key in a given file.
 * @param file File to parse
 * @param key Configuration key
 * @param out Array to store output in
 * @param len Length of output array
 * @return Number of bytes in output string
 */
size_t SDUtils::getConfigValue(const char *file, const char *key, char *out, size_t len)
{
  ifstream inFile(file);

  size_t ret = 0;
  char buffer[100];
  while (inFile.getline(buffer, 100, '\n') || inFile.gcount())
  {
    // Skip empty lines
    if (strlen(buffer) == 0)
      continue;

    // Get key
    char *k = strtok(buffer, "=");

    if (strcmp(k, key) == 0)
    {
      // Get value
      k = strtok(NULL, "=");

      strcpy(out, k);
      ret = strlen(out);
    }
  }

  return ret;
}
