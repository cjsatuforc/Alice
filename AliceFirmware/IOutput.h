/** @file */

#ifndef _ALICE_IOUTPUT_H_
#define _ALICE_IOUTPUT_H_

#include "AliceObject.h"

/**
 * @class IOutput
 * @brief Represents an output device.
 *
 * Input is provided to the IOutput::setValues function in the form of an
 * array, the channel bounds passed to IOutput::IOutput denote which subsection
 * of this array is used for the output channels of a IOutput device.
 */
class IOutput : public AliceObject
{
  public:
    IOutput(char * name, channelnumber_t start, channelnumber_t end);
    virtual ~IOutput();

    size_t numChannels() const;
    channelnumber_t startChannel() const;
    channelnumber_t endChannel() const;

    bool setValues(usvalue_t *values, size_t numValues);

    usvalue_t valueByIndex(size_t idx) const;
    usvalue_t valueByChannel(channelnumber_t channelNumber) const;

  protected:
    usvalue_t * m_values; //!< Output values
    const size_t m_numChannels; //!< Number of output channels

  private:
    const channelnumber_t m_startChannel; //!< First channel to be output
    const channelnumber_t m_endChannel; //!< Last channel to be output
};

#endif
