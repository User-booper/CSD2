#ifndef _ADDITIVESYNTH_H
#define _ADDITIVESYNTH_H
#include <iostream>
#include <cmath>
#include "synth.h"
#include "sine.h"


/* AdditiveSynth has a maximum of six sine-oscillators.
Array ratios defines the relationships these sines have to the variable frequency.

TODO:
- Maybe individual phases per oscillator
*/

class AdditiveSynth : public Synth{
public:
  explicit AdditiveSynth(float samplerate, int num_osc); 
  ~AdditiveSynth() override;

  void prepare(float samplerate) override;
  void setFrequencies(float frequency) override;
  void setAmplitudes(float amplitude, int index);
  void setRatio(float ratio, int index);
  float getNextSample() override;

private:
  Sine sines[6];
  int num_osc;
  float amplitudes[6] = {0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f};
  float ratios[6] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
  float ratio;
};
#endif