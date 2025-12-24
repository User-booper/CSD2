#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, float amplitude, float samplerate) : Oscillator(frequency, amplitude, samplerate)
{}

Sine::~Sine() {}

void Sine::calculate(){
  sample = sin(pi * 2 * phase) * amplitude;
}

