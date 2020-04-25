#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

using namespace std;

/*
------------------------------------------------------------------------------------------------
- START COPY-PASTE OF CACOPHONY NOTE LIBRARY CODE. TEENSY HATES THE C++ STD LIBRARY, 
- AND WILL NOT COMPILE UNLESS YOU DIRECTLY DECLARE USAGE OF ANY STD LIBRARY FUNCTIONALITY 
- IN THE SKETCH FILE. I RESENT THIS.
------------------------------------------------------------------------------------------------
*/
int absVal(int x)
{
    if (x < 0) {
        return -x;
    }
    return x;
}

//https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


//https://www.tutorialspoint.com/find-closest-number-in-array-in-cplusplus
int getNearest(int x, int y, int target) {
    if (target - x >= y - target)
        return y;
    else
        return x;
}
int getNearestElement(vector<int> arr, int n, int target) {
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];
    int left = 0, right = n, mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (target < arr[mid]) {
            if (mid > 0 && target > arr[mid - 1])
                return getNearest(arr[mid - 1], arr[mid], target);
            right = mid;
        }
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getNearest(arr[mid], arr[mid + 1], target);
            left = mid + 1;
        }
    }
    return arr[mid];
}

//https://stackoverflow.com/questions/4229870/c-algorithm-to-calculate-least-common-multiple-for-multiple-numbers
int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

enum class NoteLetter { A, B, C, D, E, F, G };
enum class NoteSymbol { FLAT, SHARP, NONE };

struct NoteName {
public:

  NoteName(NoteLetter letter, NoteSymbol symbol);

  NoteLetter mLetter;
  NoteSymbol mSymbol;

  string printName();

  friend bool operator==(const NoteName& c1, const NoteName& c2);

};

NoteName::NoteName(NoteLetter letter, NoteSymbol symbol) : mLetter(letter), mSymbol(symbol) {}

string NoteName::printName()
{
  string out = "";

  switch (mLetter) {
    case NoteLetter::A:
      out += "A";
      break;
    case NoteLetter::B:
      out += "B";
      break;
    case NoteLetter::C:
      out += "C";
      break;
    case NoteLetter::D:
      out += "D";
      break;
    case NoteLetter::E:
      out += "E";
      break;
    case NoteLetter::F:
      out += "F";
      break;
    case NoteLetter::G:
      out += "G";
  }

  switch (mSymbol) {
    case NoteSymbol::FLAT:
      out += "b";
      break;
    case NoteSymbol::SHARP:
      out += "#";
  }

  return out;
}

bool operator==(const NoteName& c1, const NoteName& c2)
{
  return (int)c1.mLetter == (int)c1.mSymbol &&
    (int)c2.mLetter == (int)c2.mSymbol;
}


class Note {

public:

  Note(double fundamental, int cmd = 1, int vel = 0x45);
  int mChannel, mVel;
  int mNote;
  double mFundamental;
  vector<NoteName> mNoteNames;

  static double getFundamental(int);

private:

  int getNoteFromFundamental();
  int getNoteFromFundamental(double);
  void getNoteNamesFromMIDINumber(vector<NoteName>&, int);

};

Note::Note(double fundamental, int channel, int vel) : mChannel(channel), mVel(vel), mFundamental(fundamental) { 

  mNote = getNoteFromFundamental(fundamental); 
  getNoteNamesFromMIDINumber(mNoteNames, mNote);

};

double Note::getFundamental(int note){

  return pow(2.0, (((double)note - 69.0) / 12.0)) * 440.0;

}

int Note::getNoteFromFundamental() {

  return round(69.0 + (12.0 * log2(mFundamental / 440.0)));

}

int Note::getNoteFromFundamental(double f) {

  return round(69.0 + (12.0 * log2(f / 440.0)));

}

void Note::getNoteNamesFromMIDINumber(vector<NoteName>& noteNames, int midiNo) {

  midiNo -= 9; // shift MIDI scale such that 12 == A0

  switch (midiNo % 12)
  {
    case 0:
      noteNames.push_back(NoteName(NoteLetter::A, NoteSymbol::NONE));
      break;
    case 1:
      noteNames.push_back(NoteName(NoteLetter::A, NoteSymbol::SHARP));
      noteNames.push_back(NoteName(NoteLetter::B, NoteSymbol::FLAT));
      break;
    case 2:
      noteNames.push_back(NoteName(NoteLetter::B, NoteSymbol::NONE));
      break;
    case 3:
      noteNames.push_back(NoteName(NoteLetter::C, NoteSymbol::NONE));
      break;
    case 4:
      noteNames.push_back(NoteName(NoteLetter::C, NoteSymbol::SHARP));
      noteNames.push_back(NoteName(NoteLetter::D, NoteSymbol::FLAT));
      break;
    case 5:
      noteNames.push_back(NoteName(NoteLetter::D, NoteSymbol::NONE));
      break;
    case 6:
      noteNames.push_back(NoteName(NoteLetter::D, NoteSymbol::SHARP));
      noteNames.push_back(NoteName(NoteLetter::E, NoteSymbol::FLAT));
      break;
    case 7:
      noteNames.push_back(NoteName(NoteLetter::E, NoteSymbol::NONE));
      break;
    case 8:
      noteNames.push_back(NoteName(NoteLetter::F, NoteSymbol::NONE));
      break;
    case 9:
      noteNames.push_back(NoteName(NoteLetter::F, NoteSymbol::SHARP));
      noteNames.push_back(NoteName(NoteLetter::G, NoteSymbol::FLAT));
      break;
    case 10:
      noteNames.push_back(NoteName(NoteLetter::G, NoteSymbol::NONE));
      break;
    case 11:
      noteNames.push_back(NoteName(NoteLetter::G, NoteSymbol::SHARP));
      noteNames.push_back(NoteName(NoteLetter::A, NoteSymbol::FLAT));
      break;
    default:
      break;
  }
}

class Interval {

public:

  Interval(Note one = 0, Note two = 0);

  int numerator;
  int denominator;
  int dissonance;

  int getDissonance();
  static int getDissonance(Note one, Note two);

private:

  void setDissonance();
  void setNumeratorDenominator(Note one, Note two);

};

Interval::Interval(Note one, Note two) {

  setNumeratorDenominator(one, two);
  setDissonance();

}

int Interval::getDissonance()
{
  return dissonance;
}

int Interval::getDissonance(Note one, Note two)
{
  int numerator = 0, denominator = 0;

  switch (absVal(((one.mNote - 9) % 12) - ((two.mNote - 9) % 12))) {
  case 0:
    numerator = 1;
    denominator = 1;
    break;
  case 1:
    numerator = 16;
    denominator = 15;
    break;
  case 2:
    numerator = 9;
    denominator = 8;
    break;
  case 3:
    numerator = 6;
    denominator = 5;
    break;
  case 4:
    numerator = 5;
    denominator = 4;
    break;
  case 5:
    numerator = 4;
    denominator = 3;
    break;
  case 6:
    numerator = 45;
    denominator = 32;
    break;
  case 7:
    numerator = 3;
    denominator = 2;
    break;
  case 8:
    numerator = 8;
    denominator = 5;
    break;
  case 9:
    numerator = 5;
    denominator = 3;
    break;
  case 10:
    numerator = 16;
    denominator = 9;
    break;
  case 11:
    numerator = 15;
    denominator = 8;
  default:
    break;
  }

  return numerator + denominator;
}

void Interval::setDissonance(){

  dissonance = numerator + denominator;

}

void Interval::setNumeratorDenominator(Note one, Note two)
{
  switch (absVal(((one.mNote - 9) % 12) - ((two.mNote - 9) % 12))) {
  case 0:
    numerator = 1;
    denominator = 1;
    break;
  case 1:
    numerator = 16;
    denominator = 15;
    break;
  case 2:
    numerator = 9;
    denominator = 8;
    break;
  case 3:
    numerator = 6;
    denominator = 5;
    break;
  case 4:
    numerator = 5;
    denominator = 4;
    break;
  case 5:
    numerator = 4;
    denominator = 3;
    break;
  case 6:
    numerator = 45;
    denominator = 32;
    break;
  case 7:
    numerator = 3;
    denominator = 2;
    break;
  case 8:
    numerator = 8;
    denominator = 5;
    break;
  case 9:
    numerator = 5;
    denominator = 3;
    break;
  case 10:
    numerator = 16;
    denominator = 9;
    break;
  case 11:
    numerator = 15;
    denominator = 8;
  default:
    break;
  }
}

class PlayedNotes {

public:

  PlayedNotes();

  vector<Note> mNotes;
  int mNumNotes;

  void add(Note n);
  int findLowestOctave();
  Note suggestNote();
  Note& operator[](int n);

};

PlayedNotes::PlayedNotes(){ mNumNotes = 0; }

void PlayedNotes::add(Note n)
{
  // if new note does not exist in list
  if (find_if(mNotes.begin(), mNotes.end(), 
    [&](const Note& it) {
      return ((it.mNote - 9) % 12) == ((n.mNote - 9) % 12); 
    }) == mNotes.end()) 
  {
    mNotes.push_back(n);
    mNumNotes++;
  }
}

int PlayedNotes::findLowestOctave()
{
  int lowest = 0;
  for (int i = 0; i < mNotes.size(); i++) {
    lowest = ((mNotes[i].mNote - 9) / 12);
  }
  return lowest;
}

Note PlayedNotes::suggestNote()
{
  vector<Note> candidates {
    Note(27.5),
    Note(29.14),
    Note(30.87),
    Note(32.7),
    Note(34.65),
    Note(36.71),
    Note(38.89),
    Note(41.2),
    Note(43.65),
    Note(46.25),
    Note(49),
    Note(51.91),
  };

  candidates.erase(remove_if(candidates.begin(), candidates.end(),
    [this](const Note& n) {
      for (Note note : mNotes) {
        if (((note.mNote - 9) % 12) == ((n.mNote - 9) % 12)) { return true; }
      }
      return false;
    }
  ), candidates.end());

  vector<int> dissonanceVals(candidates.size(), 0);

  for (int i = 0; i < candidates.size(); i++) {
    int tmp = 0;
    for_each(mNotes.begin(), mNotes.end(),
      [&](const Note& note) {
        tmp += Interval::getDissonance(candidates[i], note);
      }
    );
    dissonanceVals[i] = tmp / mNumNotes;
  } 

  int target = 0;
  for (int i = 0; i < mNumNotes - 1; i++) {
    for (int j = 1; j < mNumNotes; j++) {
      target += Interval::getDissonance(mNotes[i], mNotes[j]);
    }
  }
  target /= mNumNotes;

  vector<int> dissonanceValsSorted(dissonanceVals.begin(), dissonanceVals.end());

  sort(dissonanceValsSorted.begin(), dissonanceValsSorted.end());

  int closest = getNearestElement(dissonanceValsSorted, candidates.size(), target);

  Note tmp = candidates[distance(dissonanceVals.begin(), find(dissonanceVals.begin(), dissonanceVals.end(), closest))];

  return Note(Note::getFundamental(((tmp.mNote - 9.0) * findLowestOctave()) + 9.0));
}

Note& PlayedNotes::operator[](int n)
{
  return mNotes[n];
}
/*
------------------------------------------------------------------------------------------------
- END COPY-PASTE OF CACOPHONY NOTE LIBRARY CODE
------------------------------------------------------------------------------------------------
*/


// GUItool: begin automatically generated code
AudioInputI2S             i2s1;           //xy=331,237
AudioAnalyzeNoteFrequency freq;      //xy=519,240
AudioConnection           patchCord1(i2s1, 1, freq, 0);
AudioControlSGTL5000      audioControl;     //xy=633,517
// GUItool: end automatically generated code
// TODO: create dynamic storage for input notes

int reading;
long timePlay = 0;
int timeRead = 0;
int timeDebounce = 0;
int debounce = 200;
int click1 = 0;
int click2 = 0;
int tempo = 450;
PlayedNotes notes = PlayedNotes();


void setup() {
  audioControl.enable();
  audioControl.inputSelect(AUDIO_INPUT_LINEIN);
  Serial.begin(9600);
  AudioMemory(30);

  Serial.println(1);

  freq.begin(.15);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);

  //notes.add(Note(55, 2, 0x45));
  //notes.add(Note(69.3, 2, 0x45));
  //notes.add(Note(82.41, 2, 0x45));
  //notes.add(notes.suggestNote());
}

void loop() {

  tempo = ((double)((analogRead(A4) / 5) * 5) / 1023) * 2000;
  Serial.println(tempo);
  
  // TODO: MAIN LOOP
  // IF SWITCH IS ACTIVE, LISTEN FOR INPUT
  if(millis() - timeDebounce > debounce){
    if(digitalRead(15) == HIGH){
      if(click1 == 0){
        click1 = millis();
        while(digitalRead(15) == HIGH){
          if(millis() - click1 > 750){
            createMIDINote();
            digitalWrite(17, HIGH);
            delay(50);
          }
        }
        digitalWrite(17, LOW);
      } else if (click1 != 0 && click2 == 0){
        click2 = millis();
        if(click2 - click1 < 750){
          notes.add(notes.suggestNote());
          digitalWrite(17, HIGH);
          delay(50);
          digitalWrite(17, LOW);
          click1 = 0;
        } else {
          click1 = millis();
        }
        click2 = 0;
      }
    }
    timeDebounce = millis();
  }

  
  playMIDINotes();

  digitalWrite(16, HIGH);
  delay(50);
  digitalWrite(16, LOW);
  delay(tempo);
}

void createMIDINote() {
  double  tmp = double(freq.read());

  if(freq.probability() >= 0.85 && freq.available()) notes.add(Note(tmp));
}

void playMIDINotes(){
  reading = digitalRead(14);
  if (millis() - timePlay > debounce) {
    if (reading == HIGH){
      while(digitalRead(14) == HIGH && notes.mNotes.size() != 0){
        for(int i = 0; i < notes.mNotes.size(); i++){
          tempo = ((double)((analogRead(A4) / 5) * 5) / 1023) * 2000;
          usbMIDI.sendNoteOn(notes[i].mNote, notes[i].mVel, notes[i].mChannel);
          digitalWrite(16, HIGH);
          delay(50);
          digitalWrite(16, LOW);
          delay(tempo);
          usbMIDI.sendNoteOff(notes[i].mNote, notes[i].mVel, notes[i].mChannel);
        }
      }
    }

    timePlay = millis();
  }
}
