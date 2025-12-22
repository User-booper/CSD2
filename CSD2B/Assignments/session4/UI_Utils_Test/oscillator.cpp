#include "oscillator.h"
#include "math.h"

void Oscillator::tick(){
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
}

float Oscillator::getFrequency(){
  return frequency;
}

void Oscillator::setFrequency(float frequency){
  this->frequency = frequency;
}


float Oscillator::getSample(){
  return sample;
}

void Oscillator::setSamplerate(float samplerate){
  this->samplerate = samplerate;
}

