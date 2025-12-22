#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, float samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Saw - constructor\n";
}

Saw::~Saw() {
  std::cout << "Saw - destructor\n";
}

void Saw::setSamplerate(float samplerate) {
  this->samplerate =samplerate;
}

float Saw::getSample() {
  return sample;
}

void Saw::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
}

void Saw::calculate() { //lineaire functie = ax, 
  if (phase < 0.5f){
    sample = phase * 2;
  }
  if (phase = 0.5f){
    sample = 0;
  }
  else{
    (phase * 2) - 1;
  }
}
/* sample = phase * 2, so almost halfway through the phase the amplitude is 1, 
at the end of the cycle it is 0 (1 - 1)
and exactly halfway it is 0.
*/
//getters and setters
void Saw::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Saw::getFrequency()
{
  return frequency;
}
