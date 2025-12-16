#include "synth.h"
#include "math.h"

Synth::Synth(float samplerate){
  std::cout << "Synth - Constructor\n";
}

void Synth::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
}

Synth::~Synth(){
  std::cout << "Synth - destructor\n";
}

//method to initialise all the values for the square objects
void Synth::prepare(float samplerate){
    //int frequencies[4] = {440, 880, 1330, 1350};
    for(int i = 0; i < 4; ++i){
    squares[i].setSamplerate(samplerate);
    squares[i].setFrequency(frequencies[i]);
  }
}

//method to calculate, sum and normalise all of the square outputs
float Synth::getNextSample(){
    float sum = 0.0f;
    for(int i = 0; i < 4; ++i){
    sum += squares[i].getSample();
    squares[i].tick();
    }
    return sum * (1.0f / 4);
}