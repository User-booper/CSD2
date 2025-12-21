#include "callback.h"

Callback::Callback(float samplerate) : AudioCallback(samplerate), 
  synth(new AdditiveSynth(samplerate)){}

void Callback::prepare (int samplerate)  { 
  this->samplerate = samplerate;

  melody.prepare(samplerate);
  synth->prepare(samplerate); 

  // set start frequency
  Note currentNote = melody.getCurrentNote();
  synth->setFrequencies(currentNote.getPitch()); 
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
      //auto melodyHasTicked = melody.tick();
      //std::cout << "sanity echck" << std::endl;
      // melody.tick returns true when a new note is reached
      if (melody.tick())
      {
        /* NOTE: retrieving a copy of note, would be better to use a pointer,
         * but usage of pointers is out of scope for now.
         */
        //std::cout << "New MIDI note:\n";
        Note note = melody.getCurrentNote();
        synth->setFrequencies(note.getPitch()); //was: square.setFrequency()
        }
      }
    }
  }
