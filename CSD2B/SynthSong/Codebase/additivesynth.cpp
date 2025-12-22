#include "additivesynth.h"

AdditiveSynth::AdditiveSynth(float samplerate) : Synth(samplerate),
  sines {{440.0f, 0.8f, samplerate}, {440.0f, 0.8f, samplerate}, {440.0f, 0.8f, samplerate}, 
  {440.0f, 0.8f, samplerate}, {440.0f, 0.8f, samplerate}, {440.0f, 0.8f, samplerate}}
{
  std::cout << "AdditiveSynth - Constructor\n";
}

AdditiveSynth::~AdditiveSynth(){
  std::cout << "AdditiveSynth - Destructor\n";
}

void AdditiveSynth::prepare(float samplerate){
  this->samplerate = samplerate;
  for(int i = 0; i < 6; ++i){
    sines[i].setSamplerate(samplerate);
  }
}

void AdditiveSynth::setFrequencies(float frequency){
  for(int i = 0; i < 6; ++i){
    float freq = frequency * ratios[i];
    sines[i].setFrequency(freq);
  }
}


float AdditiveSynth::getNextSample(){
  float sum = 0.0f;
    for(int i = 0; i < 6; ++i){
    sum += sines[i].getSample();
    sines[i].tick();
    }
    return sum * (1.0f / 6);
}
