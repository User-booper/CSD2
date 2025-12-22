#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>
#include <cmath>

class Oscillator
{
public:
  virtual void calculate() = 0;
  void tick();
  void setFrequency(float frequency);

  void setSamplerate(float samplerate);
  float getSample();
  float getFrequency();


private:
  float frequency;
  float phase;
  float samplerate;
  float amplitude;

  // sample contains the current sample
  float sample;
  float samplerate;
};

#endif