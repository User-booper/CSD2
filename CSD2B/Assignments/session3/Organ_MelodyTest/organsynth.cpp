#include "organsynth.h"

OrganSynth::OrganSynth(float samplerate)
    : Synth(samplerate), 
    squares {{440, samplerate}, {660, samplerate}, {665, samplerate}}
{    
  std::cout << "OrganSynth - constructor\n";
}


OrganSynth::~OrganSynth(){
  std::cout << "OrganSynth - destructor\n";
}

//method to initialise all the values for the square objects
void OrganSynth::prepare(float samplerate){
    //int frequencies[4] = {440, 880, 1330, 1350};
    for(int i = 0; i < 3; ++i){
    //squares[i].setSamplerate(samplerate);
    squares[i].setFrequency(frequency * frequencymod[i]);
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