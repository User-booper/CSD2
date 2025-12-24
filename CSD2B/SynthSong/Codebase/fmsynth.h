#ifndef _FMSYNTH_H_
#define _FMSYNTH_H_

#include "synth.h"
#include "sine.h"

class FMSynth : public Synth{
  public:
  explicit FMSynth(float samplerate, float ratio, float moddepth);
 ~FMSynth() override;

  void prepare(float samplerate) override;
  void setFrequencies(float frequency) override;
  float getNextSample() override;

  private:
  float moddepth;
  float ratio = 3;
  Sine carrier;
  Sine modulator;
};


#endif