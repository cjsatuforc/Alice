/*! \file */

#ifndef _ALICETESTS_MOCKINPUT_H_
#define _ALICETESTS_MOCKINPUT_H_

#include <IInput.h>

class MockInput : public IInput
{
  public:
    MockInput(char * name, InputType type, usvalue_t v)
      : IInput(name, type)
      , m_value(v)
    {
    }

    virtual ~MockInput() {};

    void setValue(usvalue_t v)
    {
      m_value = v;
    }

    virtual usvalue_t value() const
    {
      return m_value;
    }

  private:
    usvalue_t m_value;
};

#endif
