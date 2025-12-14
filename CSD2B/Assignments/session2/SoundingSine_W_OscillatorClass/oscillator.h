#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>
#include <cmath>

class Oscillator
{
public:
  virtual void calculate() = 0;
  void tick();

private:
  float frequency;
  float phase;
  float samplerate;
};

#endif