#include "organsynth.h"

OrganSynth::OrganSynth(float samplerate)
    : Synth(samplerate), 
    squares {{440.0f, 0.8f, samplerate}, {660.0f, 0.8f, samplerate}, {665.0f, 0.8f, samplerate}}
{    
  std::cout << "OrganSynth - constructor\n";
}


OrganSynth::~OrganSynth(){
  std::cout << "OrganSynth - destructor\n";
}

//method to initialise all the values for the square objects
void OrganSynth::prepare(float samplerate){
  this->samplerate = samplerate;
  for(int i = 0; i < 3; ++i){
  squares[i].setSamplerate(samplerate);
  //squares[i].setFrequency(frequency * frequencymod[i]);
  }
} 

void OrganSynth::setFrequencies(float frequency) {
    for (int i = 0; i < 3; ++i) {
        float freq = frequency * frequencymod[i];
        squares[i].setFrequency(freq);
        std::cout << "Oscillator " << i << " frequency: " << freq << "\n";
    }
}

//method to calculate, sum and normalise all of the square outputs
float OrganSynth::getNextSample(){
    float sum = 0.0f;
    for(int i = 0; i < 3; ++i){
    sum += squares[i].getSample();
    squares[i].tick();
    }
    return sum * (1.0f / 3);
}