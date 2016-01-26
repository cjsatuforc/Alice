/** @file */

#ifndef _ALICE_SERIALOUTPUT_H_
#define _ALICE_SERIALOUTPUT_H_

#include "IOutput.h"

/**
 * @class SerialOutput
 * @brief Output device to output verbose/debug data to a serial port.
 */
class SerialOutput : public IOutput
{
public:
  SerialOutput(char *name, channelnumber_t start, channelnumber_t end, const Stream &stream);
  virtual ~SerialOutput();

  /**
   * @copydoc IOutput::open
   *
   * Always returns true.
   */
  bool open()
  {
    return true;
  }

  /**
   * @copydoc IOutput::close
   *
   * Always returns false.
   */
  bool close()
  {
    return false;
  }

  /**
   * @copydoc IOutput::isOpen
   *
   * Always returns true.
   */
  bool isOpen() const
  {
    return true;
  }

  bool tx();

private:
  const Stream &m_stream;
};

#endif
