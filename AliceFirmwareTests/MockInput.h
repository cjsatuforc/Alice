/*! \file */

#ifndef _ALICETESTS_MOCKINPUT_H_
#define _ALICETESTS_MOCKINPUT_H_

#include <IInput.h>

class MockInput : public IInput
{
  public:
    MockInput(char * name, InputType type, cevalue_t v = 0.0)
      : IInput(name, type)
      , m_value(v)
    {
    }

    virtual ~MockInput() {};

    void setValue(cevalue_t v)
    {
      m_value = v;
    }

    virtual cevalue_t value() const
    {
      return m_value;
    }

  private:
    cevalue_t m_value;
};

#endif
