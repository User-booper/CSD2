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
  void setSamplerate(float samplerate);

protected:
  float samplerate;
};

#endif