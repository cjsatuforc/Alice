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

    /**
     * @copydoc IOutput::open
     *
     * Always returns true.
     */
    bool open() { return true; };

    /**
     * @copydoc IOutput::close
     *
     * Always returns true.
     */
    bool close() { return true; };

    /**
     * @copydoc IOutput::isOpen
     *
     * Always returns true.
     */
    bool isOpen() const { return true; };

    /**
     * @copydoc IOutput::tx
     *
     * Always returns true.
     */
    bool tx() { return true; };
};

#endif
