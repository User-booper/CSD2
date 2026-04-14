#include "callback.h"


CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), sampleRate (sampleRate),
  bitcrusher(2.0f, 1.0f), 
  filter(0.5f, 1.0f) {}

void CustomCallback::prepare (int rate) {
  sampleRate = (float) rate;
  std::cout << "\nsamplerate: " << sampleRate << "\n";

    sine.prepare(sampleRate);
    sine.setFrequency(targetParameter);

  oscServer.init (serverport);
  oscServer.set_callback ("/parameter", "f");

  oscServer.start();
  std::cout << "OSC Server listening on port: " << serverport << std::endl;
}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    float filterCoefficient = 0.1f + targetParameter * 0.89f;
    filter.setCoefficient(filterCoefficient);
    
    float bitDepth = 1.0f + targetParameter * 15.0f;  //parameter modulates the bitdepth of the botcrush
    bitcrusher.setBitDepth(bitDepth);

    for (int sample = 0u; sample < numFrames; ++sample) {

      float drySignal = sine.getSample();
      float filtered = 0.0f;
      float wetSignal = 0.0f;
      
      //filter.applyEffect(drySignal, filtered);
      bitcrusher.applyEffect(filtered, wetSignal);

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            outputChannels[channel][sample] = wetSignal * 0.2; //sine.getSample();
        }
        sine.tick();
    }
}
