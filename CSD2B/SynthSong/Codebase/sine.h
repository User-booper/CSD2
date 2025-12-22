#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include <cmath>
#include "oscillator.h"

class Sine: public Oscillator
{
public:
  //Constructor and destructor
  explicit Sine(float frequency = 440.0f,
  float amplitude = 0.5f,
  float samplerate = 44100.0f);
  ~Sine();
  
  void calculate();

private:
  const float pi = acos (-1);  //atan(1) * 4; <-- vak van Pieter.
};

#endif
