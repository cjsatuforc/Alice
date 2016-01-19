/** @file */

#ifndef _ALICETESTS_MOCKOUTPUT_H_
#define _ALICETESTS_MOCKOUTPUT_H_

#include <IOutput.h>

/**
 * @class MockOutput
 * @brief Mocks an output device.
 */
class MockOutput : public IOutput
{
  public:
    /**
     * @copydoc IOutput::IOutput
     */
    MockOutput(char * name, channelnumber_t start, channelnumber_t end)
      : IOutput(name, start, end)
    {
    }

    virtual ~MockOutput() {};
};

#endif
