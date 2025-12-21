#ifndef _ADDITIVESYNTH_H
#define _ADDITIVESYNTH_H
#include <iostream>
#include <cmath>
#include "synth.h"
#include "sine.h"

/* AdditiveSynth has a maximum of six sine-oscillators.
Array ratios defines the relationships these sines have to the variable frequency.


TODO:
UIutils implementation
User sets Array of ratios, and amplitude and defines the frequency.
- Maybe individual phases for
*/

class AdditiveSynth : public Synth{
public:
  explicit AdditiveSynth(float samplerate);
  ~AdditiveSynth() override;

  void prepare(float samplerate) override;
  void setFrequencies(float frequency) override;
  //void setAmplitudes();
  float getNextSample() override;

  float ratios[6] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
  // float amplitudes[6] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
  Sine sines[6];
private:
  float frequency;
  float samplerate;
  float num_osc;

};
#endif