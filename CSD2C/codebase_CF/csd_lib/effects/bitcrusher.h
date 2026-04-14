#pragma once
#include "effect.h"
#include <cmath>

class Bitcrusher : public Effect
{
public:
    Bitcrusher(float bitDepth = 8.0f, float dryWet = 1.0f);
    ~Bitcrusher();

    void applyEffect(const float &input, float &output) override;
    void setBitDepth(float bitDepth);

private:
    double QL = 1.0;
    float bitDepth = 8.0f;
};
    /*Parameters: 
- double QL: quantization level
- new bit_depth



Formule: QL = 2 / (2^ new_bit_depth - 1)

*/


/* Member variables volgens Pirkle: (type, name, description)
- BitCrusherParamaters - paramaters (custom data structure)
- double - QL (the discrete quantization level)



Member Functions: (return type, name, description)
- BitCrusherParamaters - getParamaters - get all paramaters at once
- void - setParamaters (paramaters: _BitCrusherParamaters, _paramaters) - set all paramaters at once
- bool - reset (paramaters: double sampleRate) - reset samplerate
- double - processAudioSample (paramaters: double xn) - process input xn through the phaser

*/

