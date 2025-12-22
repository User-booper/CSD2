#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, float amplitude, float samplerate) : Oscillator(frequency, amplitude, samplerate)
{
  std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calculate(){
  sample = sin(pi * 2 * phase) * amplitude;
}

