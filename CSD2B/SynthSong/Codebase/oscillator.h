#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>
#include <cmath>


class Oscillator
{
public:
  Oscillator (float frequency, float samplerate);
  ~Oscillator();

  void setSamplerate(float samplerate);
  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //setters and getters.
  void setFrequency(float frequency);
  float getFrequency();

  void setAmplitude(float amplitude);
  float getAmplitude(float amplitude);

protected:
  virtual void calculate() = 0;
  float frequency;
  float phase;
  float samplerate;

  float amplitude { 0.4f };
  float sample;

};

#endif