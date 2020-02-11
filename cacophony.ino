#include "lib/Note.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S             i2s1;           //xy=331,237
AudioAnalyzeNoteFrequency freq;      //xy=519,240
AudioConnection           patchCord1(i2s1, 1, freq, 0);
AudioControlSGTL5000      audioControl;     //xy=633,517
// GUItool: end automatically generated code
// TODO: create dynamic storage for input notes

void setup() {
  audioControl.enable();
  audioControl.inputSelect(AUDIO_INPUT_LINEIN);
  Serial.begin(9600);
  AudioMemory(30);

  freq.begin(.15);
}

void loop() {
  // TODO: MAIN LOOP
  // IF SWITCH IS ACTIVE, LISTEN FOR INPUT
  if (freq.available() && freq.probability() > 0.75) {
    createMIDINote();
  } else {
    Serial.println("no note detected");
  }

  delay(250);
}

void createMIDINote() {
  double  tmp = double(freq.read()),
          noteFreq = tmp;
  Note note = Note(noteFreq);

  //TODO: PREVENT DUPLICATE NOTES FROM BEING PUSHED TO VECTOR

  // TODO: ADD NOTE TO DYNAMIC STORAGE
  Serial.print("note detected: ");
  Serial.print(freq.read());
  Serial.print("; probability: ");
  Serial.println(freq.probability());
  Serial.print("MIDI note #");
  Serial.println(note.mNote);
}
