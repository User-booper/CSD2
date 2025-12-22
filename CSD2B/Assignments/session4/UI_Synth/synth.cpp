#include "synth.h"
#include "math.h"

Synth::Synth(float samplerate)
 : samplerate(samplerate)
{
  std::cout << "Synth - Constructor\n";
}

void Synth::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
}

Synth::~Synth(){
  std::cout << "Synth - destructor\n";
}



