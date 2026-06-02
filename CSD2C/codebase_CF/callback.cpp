#include "callback.h"


CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), sampleRate (sampleRate),
  bitcrusher(2.0f, 1.0f), 
  filter(0.5f, 1.0f) {}

void CustomCallback::prepare (int rate) {
  sampleRate = (float) rate;
  std::cout << "\nsamplerate: " << sampleRate << "\n";

    sine.prepare(sampleRate);
    square.prepare(sampleRate);
    std::cout << targetParameter << "\n";
    sine.setFrequency(50);
    square.setFrequency(200);
    filter.setCoefficient(0.5f);

  oscServer.init (serverport);
  oscServer.set_callback ("/parameter", "f");

  oscServer.start();
  std::cout << "OSC Server listening on port: " << serverport << std::endl;
}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    //float filterCoefficient = 0.2f + targetParameter * 0.5f;
    //std::cout << "Filter Coeff " << filterCoefficient << std::endl;
    float filterCoeff = lerp(targetParameter, 0.2, 0.9);
    filter.setDryWet(filterCoeff);
    //float oscfreq = lerp(targetParameter, 60, 120);
   // square.setFrequency(oscfreq);
    
    // float bitDepth = 2.0f + targetParameter; //* 15.0f;  //parameter modulates the bitdepth of the botcrush
    float bitDepth = lerp(targetParameter, 2, 8);
    bitcrusher.setBitDepth(bitDepth);

    for (int sample = 0u; sample < numFrames; ++sample) {

      float drySignal = sine.getSample(); //+ (square.getSample() * 0.3);
      float filtered = 0.0f;
      float wetSignal = 0.0f;
      
      bitcrusher.applyEffect(drySignal, wetSignal);
      filter.applyEffect(wetSignal, wetSignal);
      
        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            outputChannels[channel][sample] = wetSignal * 0.5; //sine.getSample();
        }
        sine.tick();
        square.tick();
    }
}
