#include "lib/Note.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S             i2s1;           //xy=331,237
AudioAnalyzeNoteFrequency freq;      //xy=519,240
AudioConnection           patchCord1(i2s1, 0, freq, 0);
AudioControlSGTL5000      audioControl;     //xy=633,517
// GUItool: end automatically generated code
// TODO: create dynamic storage for input notes

void setup() {
  Serial.begin(9600);

  audioControl.enable();
  audioControl.inputSelect(AUDIO_INPUT_LINEIN);

  AudioMemory(30);
  
  freq.begin(.15);
}

void loop() {
  // TODO: MAIN LOOP
  // IF SWITCH IS ACTIVE, LISTEN FOR INPUT
  
  if(freq.available() && freq.probability() > 0.75){
    createMIDINote();
  }
}

void createMIDINote(){
  double  tmp = double(freq.read()),
          noteFreq = tmp;

  //TODO: PREVENT DUPLICATE NOTES FROM BEING PUSHED TO VECTOR

  if(noteFreq != -1){
    // TODO: ADD NOTE TO DYNAMIC STORAGE
  }
}
