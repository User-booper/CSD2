#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include <cmath>
#include "oscillator.h"

class Saw: public Oscillator
{
public:
  //Constructor and destructor
  explicit Saw(float frequency = 440.0f,
  float amplitude = 0.5f,
  float samplerate = 44100.0f);
  ~Saw();
  
  void calculate();

private:

};

#endif
