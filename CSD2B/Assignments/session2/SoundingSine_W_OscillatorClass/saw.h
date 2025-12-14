#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include <cmath>

class Saw
{
public:
  //Constructor and destructor
  Saw(float frequency, float samplerate = 44100);
  ~Saw();
  void setSamplerate(float samplerate);
  //return the current sample
  float getSample();
  // go to next sample
  void tick();
  void calculate();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

private:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  float samplerate;
};

#endif
