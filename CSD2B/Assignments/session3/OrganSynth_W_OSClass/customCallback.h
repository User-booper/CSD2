#include "audiocomponent.h"
//  Daan Schrier
#include "square.h"
#include "oscillator.h"
#include "synth.h"
#include "organsynth.h"

struct CustomCallback : AudioCallback {
    explicit CustomCallback (double Fs) : AudioCallback(Fs), synth(new OrganSynth(Fs)) {
        synth->prepare(Fs);
    }

    ~CustomCallback() override {
        delete synth;
    }

    void prepare (int sampleRate) override {
        synth->prepare(sampleRate);
    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                // write sample to buffer at channel 0, amp = 0.25
                outputChannels[channel][sample] = synth->getNextSample();
            }
        }
    }

private:
  Synth* synth;
};
