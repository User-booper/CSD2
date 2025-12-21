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
  void setFrequencies(float frequency) override;
  float getNextSample() override;


  Square squares[3];
  float frequency;
  float frequencymod[3] = {1.0f, 1.5f, 1.51f}; 
  //frequencymod is the ratio of the different organsynth oscillators, compared to the root.
};

#endif
