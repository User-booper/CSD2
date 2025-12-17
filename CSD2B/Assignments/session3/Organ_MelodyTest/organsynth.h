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
  //int frequencies[3] = {440, 660, 665};
  int frequency;
  float frequencymod[3] = {1.0, 1.5, 1.51}; 
  //frequencymod is the ratio of the different organsynth oscillators, compared to the root.
};

#endif
