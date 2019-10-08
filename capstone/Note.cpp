#include "Note.h"
#include <math.h>
#include <iostream>

//Note::Note(int note = 0, int cmd = 0, int vel = 0) : note(note), cmd(cmd), vel(vel) {};
Note::Note(double note, int cmd = 0, int vel = 0) : mCmd(cmd), mVel(vel) { mNote = getNoteFromFundamental(note); };

int Note::getNoteFromFundamental(double f) {
	return round(69.0 + (12.0 * log2(f / 440.0)));
}
