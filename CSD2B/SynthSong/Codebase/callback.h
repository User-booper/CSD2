#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "melody.h"
#include "synth.h"
#include "fmsynth.h"
#include "additivesynth.h"
#include "oscillator.h"


class Callback : public AudioCallback {
public:

  explicit Callback (float sampleRate);
  ~Callback();
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;

  double mtof(float mPitch);
  void updatePitch(Melody& melody, Synth& synth); //ipv Square* square

private:
  double samplerate;
  //Square square;
  Synth* synth = NULL;
  double amplitude = 0.9;
  Melody melody;
  int frameCounts = 0;

  /* instead of using bpm and specifying note lenghts we'll make every note
   * equal length and specify the delay between notes in terms of the samplerate
   *
   * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be played
   */
  double noteDelayFactor = 0.1;
};

#endif  //CALLBACK_H