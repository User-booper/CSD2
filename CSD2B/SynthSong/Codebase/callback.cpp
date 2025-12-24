#include "callback.h"
#include "uiUtilities.h"

Callback::Callback(float samplerate) : AudioCallback(samplerate) {} // synth(new FMSynth(samplerate))


Callback::~Callback(){
  delete synth;
  std::cout << "Callback - Destructor\n";
}  

void Callback::prepare (int samplerate)  { 
  this->samplerate = samplerate;
  
  std::cout << "Choose a synth. Select 0 for Additive or 1 for FM: ";
  int synthSelection = UIUtilities::retrieveValueInRange(0,1);

    //setting the parameters for the additive synth.
  if (synthSelection == 0){
    std::cout << "Chosen synth: ADDITIVE \n";
    std::cout << "Number of oscillators (between 1 and 6): ";
    int UInum_osc = UIUtilities::retrieveValueInRange(1,6);

    synth = new AdditiveSynth(samplerate, UInum_osc);

    float UIratio;
    float UIamplitude;
    //for loop to set the ratio and amplitude of every oscilator for the additive synth.
    for(int i = 0; i < UInum_osc; ++i){
      std::cout << "Ratio of Oscillator " << i + 1 << " (between 1.0 and 5.0): ";
      UIratio = UIUtilities::retrieveValueInRange(1, 5);
      synth->setRatio(UIratio, i);

      std::cout << "Amplitude of Oscillator " << i + 1 << " (between 0.0 and 1.0): ";
      UIamplitude = UIUtilities::retrieveValueInRange(0, 1);
      synth->setAmplitudes(UIamplitude, i);
      }
    }

    
  if (synthSelection == 1){
    std::cout << "Chosen synth: FREQUENCY MODULATION \n";

    std::cout << "Ratio of modulator to carrier (between 1.0 and 10.0): ";
    float UIratio = UIUtilities::retrieveValueInRange(1, 10);

    std::cout << "Modulationdepth (between 0.0 and 1.0): ";
    float UImoddepth = UIUtilities::retrieveValueInRange(0, 1);

    synth = new FMSynth(samplerate, UIratio, UImoddepth);
  }
 
  melody.prepare(samplerate);
  synth->prepare(samplerate); 

  // set start frequency
  Note currentNote = melody.getCurrentNote();
  synth->setFrequencies(currentNote.getPitch()); 
  synth->setVelocity(currentNote.getVelocity());
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

      if (melody.tick())
      {
        /* NOTE: retrieving a copy of note, would be better to use a pointer,
         * but usage of pointers is out of scope for now.
         */

        Note note = melody.getCurrentNote();
        synth->setFrequencies(note.getPitch()); 
        synth->setVelocity(note.getVelocity());
        }
      }
    }
  }
