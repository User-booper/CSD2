#include "callback.h"

Callback::Callback(float samplerate) : AudioCallback(samplerate), 
  synth(new OrganSynth(samplerate)){}

void Callback::prepare (int samplerate)  { 
  this->samplerate = samplerate;

  melody.prepare(samplerate);
  synth->prepare(samplerate); //ipv square.prepare(samplerate);

  // set start frequency
  Note currentNote = melody.getCurrentNote();
  synth->setFrequency(currentNote.getPitch()); //ipv square.setF()
}

void Callback::process(AudioBuffer buffer)  {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0; channel < numOutputChannels; ++channel) {
    for (int frame = 0; frame < numFrames; ++frame) {
      outputChannels[channel][frame] = synth->getNextSample() * amplitude;
                                        //ipv square.getSample()
      //square.tick();

      // melody.tick returns true when a new note is reached
      if (melody.tick())
      {
        /* NOTE: retrieving a copy of note, would be better to use a pointer,
         * but usage of pointers is out of scope for now.
         */
        Note note = melody.getCurrentNote();
        synth->setFrequency(note.getPitch()); //was: square.setFrequency()
      }
    }
  }
}
