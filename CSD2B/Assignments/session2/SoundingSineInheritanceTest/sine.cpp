#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, float samplerate) : Oscillator(frequency, samplerate)
{
  std::cout << "Sine - constructor\n";
}

// Sine::~Sine() {
//   std::cout << "Sine - destructor\n";
// }


void Sine::calculate(){
  std::cout << "Sine - Calculate\n";
  sample = sin(M_PI * 2 * phase) * amplitude;
}
