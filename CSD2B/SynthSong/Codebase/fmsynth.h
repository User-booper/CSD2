#ifndef _FMSYNTH_H_
#define _FMSYNTH_H_

#include "synth.h"
#include "sine.h"

class FMSynth : public Synth{
  public:
  explicit FMSynth(float samplerate);
 ~FMSynth();

  void prepare(float samplerate) override;
  void setFrequencies(float frequency) override;
  float getNextSample() override;

  void setAmplitudes(float amplitude) override;

  private:
  float amplitudes[2] = {1, 0.5};
  //float ratio;
  float fm;
  Sine carrier;
  Sine modulator;
};


#endif