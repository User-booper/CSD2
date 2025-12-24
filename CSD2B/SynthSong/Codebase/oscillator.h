#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>
#include <cmath>


class Oscillator
{
public:
  Oscillator (float frequency, float amplitude, float samplerate);
  ~Oscillator();

  void setSamplerate(float samplerate);
  //returns the current sample
  float getSample();
  // goes to next sample
  void tick();

  //setters and getters.
  void setFrequency(float frequency);
  float getFrequency();

  void setAmplitude(float amplitude);
  float getAmplitude();

protected:
  virtual void calculate() = 0;
  float frequency;
  float phase;
  float samplerate;

  float amplitude; 
  float sample;

};

#endif