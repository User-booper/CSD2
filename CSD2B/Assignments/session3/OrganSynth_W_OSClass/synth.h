#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include <cmath>
#include "square.h"

class Synth{
public:
  Synth(float samplerate);
  ~Synth();

  virtual void prepare(float samplerate) = 0;
  virtual float getNextSample() = 0;
  void setSamplerate(float samplerate);
  
  
 //Array with four square objects
  Square squares[4];

protected:
  float samplerate;
  //array with frequencies for the squares
};

#endif