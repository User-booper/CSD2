#include "square.h"
#include "math.h"

Square::Square(float frequency, float amplitude, float samplerate) 
  : Oscillator(frequency, amplitude, samplerate)
{
  std::cout << "Square - constructor\n";
}

Square::~Square() {
  std::cout << "Square - destructor\n";
}


void Square::calculate(){
  //std::cout << "Sine - Calculate\n";
  if (phase < 0.5){
    sample = 1;
  }
  else{
    sample = -1;
  }
}
