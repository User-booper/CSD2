#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include <cmath>
#include "square.h"

class Synth{
public:
  Synth(float samplerate);
  ~Synth();

  void prepare(float samplerate);
  void setSamplerate(float samplerate);
  float getNextSample();
  
 //Array with four square objects
  Square squares[4];

protected:
  float samplerate;
  //array with frequencies for the squares
  int frequencies[4] = {440, 880, 1330, 13350};
};

#endif