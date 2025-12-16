#ifndef _ORGANSYNTH_H_
#define _ORGANSYNTH_H_
#include <iostream>
#include <cmath>
#include "synth.h"


class OrganSynth : public Synth{
public: 
  OrganSynth();
  ~OrganSynth();

  //void setSamplerate();
  void prepare(float samplerate);
  float getNextSample();

  Square squares[4];
  int frequencies[4] = {440, 880, 1330, 13350};
  //float samplerate;
};

#endif
