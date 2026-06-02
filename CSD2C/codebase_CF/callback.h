#ifndef CALLBACK_H
#define CALLBACK_H

#include <audiocomponent.h>
#include "osc_server.h"
#include <sine.h>
#include <square.h>
#include <saw.h>
#include "bitcrusher.h"
#include "simpleLadder.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float sampleRate = 44100.f;
  float targetParameter { 0.5f };

  Sine sine; 
  Square square;
  Bitcrusher bitcrusher;
  simpleLadder filter;
  LocalOSC oscServer { targetParameter };
  std::string serverport {"7777"};

  float lerp (float factor, float a, float b){
    return a + (b - a) * factor;
  }

};

#endif //CALLBACK_H
