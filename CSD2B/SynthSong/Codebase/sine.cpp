#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, float amplitude, float samplerate) : Oscillator(frequency, amplitude, samplerate)
{
  //std::cout << "Sine - Constructor\n";
}

Sine::~Sine() {
  //std::cout << "Sine - Destructor\n";
}

void Sine::calculate(){
  sample = sin(pi * 2 * phase) * amplitude;
}

