#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include <cmath>
#include "square.h"

class Synth{
public:
  Synth(float samplerate);
  virtual ~Synth(); // = default;

  virtual void prepare(float samplerate) = 0;
  virtual float getNextSample() = 0;
  virtual void setFrequencies(float frequency) = 0;

//only the additivesynth overrides setAmplitudes and setRatio;
//so the methods are not pure virtual.
  virtual void setAmplitudes(float amplitude, float index){};
  virtual void setRatio(float ratio, int index){};

  void setSamplerate(float samplerate);
  void setVelocity(float Velocity);

protected:
  float samplerate;
  float synthVelocity = 1;
};

#endif