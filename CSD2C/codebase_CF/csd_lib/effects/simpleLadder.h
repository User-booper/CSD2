#include "effect.h"

class simpleLadder : public Effect {
    public:
    simpleLadder(float coefficient = 0.5f, float dryWet = 1.0f);
    ~simpleLadder();

    void setCoefficient(float coefficient) ;
    void applyEffect(const float &input, float &output) override; 
private:
    float process(float input);
    float A { 0.0 };
    float B { 0.0 };
    float C { 0.0 };
    float D { 0.0 }; 


    float b { 0.0 };
    float a { 0.0 };
};