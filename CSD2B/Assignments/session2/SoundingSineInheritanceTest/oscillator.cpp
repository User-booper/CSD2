#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator (float frequency, float samplerate)
  : frequency (frequency),
  amplitude (0.25f),
  phase (0),
  sample(0),
  samplerate (samplerate){
    std::cout << "Oscillator - constructor\n";
  }

Oscillator::~Oscillator(){
  std::cout << "Oscillator - Destructor/n";
}


//getters and setters
void Oscillator::setSamplerate(float samplerate) {
  this->samplerate =samplerate;
}

float Oscillator::getSample() {
  return sample;
}

void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}

//method to increment and wrap the phase.
void Oscillator::tick(){
  std::cout << "Oscillator tick()\n";
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  calculate();
}