#ifndef _ORGANSYNTH_H_
#define _ORGANSYNTH_H_
#include <iostream>
#include <cmath>
#include "synth.h"


class OrganSynth : public Synth{
public: 
  explicit OrganSynth(float samplerate);
  ~OrganSynth() override;

  void prepare(float samplerate) override;
  float getNextSample() override;

  Square squares[3];
  int frequencies[3] = {440, 660, 665};
  //float samplerate;
};

#endif
