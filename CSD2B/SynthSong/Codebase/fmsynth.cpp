#include "fmsynth.h"
#include <cmath>
#include <iostream>
#include "sine.h"

FMSynth::FMSynth(float samplerate, float ratio, float moddepth) : Synth(samplerate),
   carrier(440.0f, 0.9f, samplerate),
   modulator(440.0f, 0.9f, samplerate),
   ratio(ratio),
   moddepth(moddepth)
  {
  std::cout << "FMSynth - Constructor\n";
  }
  

FMSynth::~FMSynth(){
  std::cout << "FMSynth - Destructor\n";
}

void FMSynth::prepare(float samplerate){
  this->samplerate = samplerate;
  carrier.setSamplerate(samplerate);
  modulator.setSamplerate(samplerate);

  carrier.setAmplitude(moddepth);
  modulator.setAmplitude(1.0f);
}

void FMSynth::setFrequencies(float frequency){
  for(int i = 0; i < 2; ++i){
    carrier.setFrequency(frequency);
    modulator.setFrequency(frequency * ratio); 
  }
}

//calculates the next sample and ticks the modulator and carrier.
float FMSynth::getNextSample(){
  float fm = carrier.getSample() + (modulator.getSample() * modulator.getAmplitude()); //simple fm, might implement fabians formula here later.
  float fm_scaled = fm * synthVelocity;
  carrier.tick();
  modulator.tick();
  return fm_scaled;
}