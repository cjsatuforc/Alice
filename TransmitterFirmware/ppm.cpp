#include "ppm.h"

#include <Arduino.h>


#define PPM_FRAME_LENGTH 22500  //set the PPM frame length in microseconds (1ms = 1000µs)
#define PPM_PULSE_LENGTH 300  //set the pulse length
#define PPM_ON_STATE 0  //set polarity of the pulses: 1 is positive, 0 is negative
#define PPM_MAX_CHANNELS 16


int g_ppmPin;
size_t g_numChannels;
channelvalue_t g_channelVal[PPM_MAX_CHANNELS];


void ppm_init(int pin, size_t numChannels)
{
  g_ppmPin = pin;
  g_numChannels = numChannels;

  int i;
  for(i = 0; i < g_numChannels; i++)
    g_channelVal[i] = 1500;

  pinMode(g_ppmPin, OUTPUT);
  digitalWrite(g_ppmPin, !PPM_ON_STATE);

  cli();
  TCCR1A = 0; // set entire TCCR1 register to 0
  TCCR1B = 0;

  OCR1A = 100;  // compare match register, change this
  TCCR1B |= (1 << WGM12);  // turn on CTC mode
  TCCR1B |= (1 << CS11);  // 8 prescaler: 0.5 microseconds at 16mhz
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  sei();
}


int ppm_set_channel(channelid_t id, channelvalue_t value)
{
  if(id >= g_numChannels)
    return 1;

  g_channelVal[id] = value;
  return 0;
}


ISR(TIMER1_COMPA_vect)
{
  static boolean state = true;

  TCNT1 = 0;

  if(state)
  {
    digitalWrite(g_ppmPin, PPM_ON_STATE);
    OCR1A = PPM_PULSE_LENGTH * 2;
    state = false;
  }
  else
  {
    static byte cur_chan_numb;
    static unsigned int calc_rest;

    digitalWrite(g_ppmPin, !PPM_ON_STATE);
    state = true;

    if(cur_chan_numb >= g_numChannels)
    {
      cur_chan_numb = 0;
      calc_rest = calc_rest + PPM_PULSE_LENGTH;
      OCR1A = (PPM_FRAME_LENGTH - calc_rest) * 2;
      calc_rest = 0;
    }
    else
    {
      OCR1A = (g_channelVal[cur_chan_numb] - PPM_PULSE_LENGTH) * 2;
      calc_rest = calc_rest + g_channelVal[cur_chan_numb];
      cur_chan_numb++;
    }
  }
}
