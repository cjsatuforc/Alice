/** @file */

#ifndef _ALICETESTS_MOCKINPUT_H_
#define _ALICETESTS_MOCKINPUT_H_

#include <IInput.h>

/**
 * @class MockInput
 * @brief Mocks an input device.
 */
class MockInput : public IInput
{
public:
  /**
   * @copydoc IInput::IInput
   * @param type Type of input to mock
   * @param v Value held by mocked input
   */
  MockInput(char *name, InputType type, cevalue_t v = 0.0)
      : IInput(name, type)
      , m_value(v)
  {
  }

  virtual ~MockInput(){};

  /**
   * @brief Sets the value held by the mock input.
   * @param v Value
   */
  void setValue(cevalue_t v)
  {
    m_value = v;
  }

  /**
   * @copydoc IInput::value
   */
  virtual cevalue_t value() const
  {
    return m_value;
  }

private:
  cevalue_t m_value; //!< Value of the input
};

#endif
