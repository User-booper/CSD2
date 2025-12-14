#include "oscillator.h"
#include "math.h"

void Oscillator::tick(){
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
}