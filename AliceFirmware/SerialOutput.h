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
    SerialOutput(char * name, channelnumber_t start, channelnumber_t end);
    virtual ~SerialOutput();
};

#endif
