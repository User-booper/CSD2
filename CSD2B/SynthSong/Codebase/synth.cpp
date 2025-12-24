#include "synth.h"
#include "math.h"

Synth::Synth(float samplerate)
 : samplerate(samplerate)
{
  std::cout << "Synth - Constructor\n";
}

Synth::~Synth(){
  std::cout << "Synth - Destructor\n";
}

void Synth::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
}

void Synth::setVelocity(float velocity){
  synthVelocity = velocity;
}




