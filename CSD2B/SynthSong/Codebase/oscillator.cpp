#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator (float frequency, float samplerate) //float amplitude
  : frequency (frequency),
  amplitude (0.4),
  phase (0.0f),
  sample(0.0f),
  samplerate (samplerate){
    std::cout << "Oscillator - constructor\n";
  }

Oscillator::~Oscillator(){
  std::cout << "Oscillator - Destructor\n";
}


// //getters and setters
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

void Oscillator::setAmplitude(float amplitude)
{
  // TODO add check to see if parameter is valid
  this->amplitude = amplitude;
}

float Oscillator::getAmplitude(float amplitude)
{
  return amplitude;
}

//method to increment and wrap the phase.
void Oscillator::tick(){
  //std::cout << "Oscillator tick()\n";
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  calculate();
}