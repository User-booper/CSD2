#include "additivesynth.h"

AdditiveSynth::AdditiveSynth(float samplerate, int num_osc) 
  : Synth(samplerate), num_osc(num_osc)
{
  std::cout << "AdditiveSynth - Constructor\n";
}

AdditiveSynth::~AdditiveSynth(){
  std::cout << "AdditiveSynth - Destructor\n";
}


void AdditiveSynth::prepare(float samplerate){
  this->samplerate = samplerate;
  for(int i = 0; i < num_osc; ++i){
    sines[i].setSamplerate(samplerate);
  }
}



void AdditiveSynth::setRatio(float ratio, int index){
  ratios[index] = ratio; 
}

void AdditiveSynth::setAmplitudes(float amplitude, int index){
  sines[index].setAmplitude(amplitude);
}

void AdditiveSynth::setFrequencies(float frequency){
  for(int i = 0; i < num_osc; ++i){
    float freq = frequency * ratios[i];
    sines[i].setFrequency(freq);
  }
}



float AdditiveSynth::getNextSample(){
  float sum = 0.0f;
    for(int i = 0; i < num_osc; ++i){
    sum += sines[i].getSample();
    sines[i].tick();
    }
    return sum * (1.0f / num_osc);
}
