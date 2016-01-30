/** @file */

#ifndef _ALICE_PPMOUTPUT_H_
#define _ALICE_PPMOUTPUT_H_

#include "IOutput.h"

#include "cppm_encode.h"

/**
 * @class PPMOutput
 * @brief Output device to output a PPM stream.
 */
class PPMOutput : public IOutput
{
public:
  PPMOutput(char *name, channelnumber_t start, channelnumber_t end, int8_t pin, uint8_t logic = LOW,
            uint64_t frameLength = 22500, uint64_t pulseLength = 300);
  virtual ~PPMOutput();

  bool open();
  bool close();
  bool isOpen() const;
  bool tx();

  int8_t streamNumber() const;
  bool valid() const;

private:
  int8_t m_streamNumber;

  static bool s_streamsInUse[NUM_PPM_STREAMS];
};

#endif
