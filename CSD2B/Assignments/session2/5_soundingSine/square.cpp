#include "square.h"
#include "math.h"

Square::Square(float frequency, float samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Sine - constructor\n";
}

Square::~Square() {
  std::cout << "Sine - destructor\n";
}

void Square::setSamplerate(float samplerate) {
  this->samplerate =samplerate;
}

float Square::getSample() {
  return sample;
}

void Square::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  sample = sin(pi * 2 * phase) * amplitude;
}

void Square::calculate(){
    if (phase < 0.5f){
        sample = 1;
    } 
    else {
        sample = 0;
    }
}
//getters and setters
void Square::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Square::getFrequency()
{
  return frequency;
}