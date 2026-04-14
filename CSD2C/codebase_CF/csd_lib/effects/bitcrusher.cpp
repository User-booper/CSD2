#include "bitcrusher.h"
#include <cmath>
#include <iostream>

// Constructor
Bitcrusher::Bitcrusher(float bitDepth, float dryWet)
    : Effect(dryWet)
{
    setBitDepth(bitDepth);
    dryWet = 1.0f;
}

// Destructor
Bitcrusher::~Bitcrusher() {
    std::cout << "this bit has been crushed" << "/endl";
}

// Set bit depth and recompute QL
void Bitcrusher::setBitDepth(float newBitDepth)
{
    // Clamp to valid range
    if (newBitDepth < 1.0f)
        newBitDepth = 1.0f;

    bitDepth = newBitDepth;

    // QL = 2 / (2^N - 1)
    QL = 2.0 / (std::pow(2.0, bitDepth) - 1.0);
}

// Apply bitcrushing
void Bitcrusher::applyEffect(const float &input, float &output)
{
    float crushed = QL * std::round(input / QL);

    output = (1.0f - dryWet) * input + dryWet * crushed;
}