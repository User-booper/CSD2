#include "fmsynth.h"
#include <cmath>
#include <iostream>
#include "sine.h"

FMSynth::FMSynth(float samplerate) : Synth(samplerate),
   carrier(440.0f, 0.9f, samplerate),
   modulator(440.0f, 0.9f, samplerate)
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
}

void FMSynth::setFrequencies(float frequency){
  for(int i = 0; i < 2; ++i){
    carrier.setFrequency(frequency);
    modulator.setFrequency(frequency * 2); //*2 replace with ratio later on
  }
}

void FMSynth::setAmplitudes(float amplitude){
  for(int i = 0; i < 2; ++i){
    carrier.setAmplitude(amplitude);
  }
}

float FMSynth::getNextSample(){
  float fm = carrier.getSample() + (modulator.getSample() * modulator.getAmplitude()); //simple fm, might implement fabians formula here later.
  carrier.tick();
  modulator.tick();
  return fm;
}