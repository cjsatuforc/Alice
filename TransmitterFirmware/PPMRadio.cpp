#include "PPMRadio.h"


PPMRadio::PPMRadio(int pin, size_t numChannels) : IRadio()
{
  m_ppmPin = pin;
  m_numChannels = numChannels;

  int i;
  for(i = 0; i < m_numChannels; i++)
    m_channelVal[i] = 1500;

  pinMode(m_ppmPin, OUTPUT);
  digitalWrite(m_ppmPin, !ON_STATE);
}

bool PPMRadio::setChannel(channelid_t id, channelvalue_t value)
{
  if(id >= m_numChannels)
    return false;

  m_channelVal[id] = value;
  return true;
}

bool PPMRadio::open()
{
  cli();
  TCCR1A = 0; // set entire TCCR1 register to 0
  TCCR1B = 0;

  OCR1A = 100;  // compare match register, change this
  TCCR1B |= (1 << WGM12);  // turn on CTC mode
  TCCR1B |= (1 << CS11);  // 8 prescaler: 0.5 microseconds at 16mhz
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  sei();

  m_open = true;
  return true;
}

void PPMRadio::isr()
{
  TCNT1 = 0;

  if(m_state)
  {
    digitalWrite(m_ppmPin, ON_STATE);
    OCR1A = PULSE_LENGTH_MS * 2;
    m_state = false;
  }
  else
  {
    digitalWrite(m_ppmPin, !ON_STATE);
    m_state = true;

    if(m_currentChannelID >= m_numChannels)
    {
      m_currentChannelID = 0;
      m_calcRest = m_calcRest + PULSE_LENGTH_MS;
      OCR1A = (FRAME_LENGTH_MS - m_calcRest) * 2;
      m_calcRest = 0;
    }
    else
    {
      OCR1A = (m_channelVal[m_currentChannelID] - PULSE_LENGTH_MS) * 2;
      m_calcRest = m_calcRest + m_channelVal[m_currentChannelID];
      m_currentChannelID++;
    }
  }
}


ISR(TIMER1_COMPA_vect)
{
  PPMRadio::isr();
}

bool PPMRadio::m_open;
int PPMRadio::m_ppmPin;
size_t PPMRadio::m_numChannels;
channelvalue_t PPMRadio::m_channelVal[16];
bool PPMRadio::m_state;
byte PPMRadio::m_currentChannelID;
unsigned int PPMRadio::m_calcRest;
