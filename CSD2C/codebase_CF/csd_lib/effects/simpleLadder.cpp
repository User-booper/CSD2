#include "simpleLadder.h"
#include "cmath"
#include <iostream>

simpleLadder::simpleLadder(float coefficient, float dryWet)
: Effect(dryWet) {
  setCoefficient(coefficient);
}

simpleLadder::~simpleLadder(){
    std::cout << "only snakes left" << "/endl";
}

float simpleLadder::process(float input){
    A = b * input + (a * A);
    B = b * A + (a * B);
    C = b * B + (a * C);
    D = b * C + (a * D);
    return D;
}

void simpleLadder::setCoefficient(float coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }

void simpleLadder::applyEffect(const float &input, float &output){
    float filtered = process(input);
    output = (1.0f - dryWet) * input + dryWet * filtered;
}   

//coefficient determines cutoff, the higher the coefficient the more frequencies get filtered.