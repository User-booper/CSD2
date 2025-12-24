#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, float amplitude, float samplerate) : Oscillator(frequency, amplitude, samplerate)
{}

Saw::~Saw() {}

void Saw::calculate(){
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