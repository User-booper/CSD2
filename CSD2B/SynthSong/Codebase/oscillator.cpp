#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator (float frequency, float amplitude, float samplerate) //float amplitude
  : frequency (frequency),
  amplitude (amplitude),
  phase (0.0f),
  sample(0.0f),
  samplerate (samplerate){
    //std::cout << "Oscillator - constructor\n";
  }

Oscillator::~Oscillator(){
  //std::cout << "Oscillator - Destructor\n";
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
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}

void Oscillator::setAmplitude(float amplitude)
{
  this->amplitude = amplitude;
}

float Oscillator::getAmplitude()
{
  return amplitude;
}

//method to increment and wrap the phase.
void Oscillator::tick(){
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  calculate();
}