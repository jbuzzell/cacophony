#include "Note.h"
#include <math.h>

Note::Note(double fundamental, int channel, int vel) : mChannel(channel), mVel(vel), mFundamental(fundamental) { 
	mNote = getNoteFromFundamental(fundamental); 
};

double Note::getFundamental() {

	return 12 * log2(mNote / 440.0) + 69;

}

int Note::getNoteFromFundamental() {

	return round(69.0 + (12.0 * log2(mFundamental / 440.0)));

}

int Note::getNoteFromFundamental(double f) {

	return round(69.0 + (12.0 * log2(f / 440.0)));

}

std::vector<NoteName> Note::getNoteNamesFromMIDINumber(int midiNo) {

	midiNo -= 9; // shift MIDI scale such that 12 == A0

	switch (midiNo)
	{
		case 0:
			return { NoteName(A, NONE) };
		case 1:
			return { NoteName(A, SHARP), NoteName(B, FLAT) };
		case 2:
			return { NoteName(B, NONE) };
		case 3:
			return { NoteName(C, NONE) };
		case 4:
			return { NoteName(C, SHARP), NoteName(D, FLAT) };
		case 5:
			return { NoteName(D, NONE) };
		case 6:
			return { NoteName(D, SHARP), NoteName(E, FLAT) };
		case 7:
			return { NoteName(E, NONE) };
		case 8:
			return { NoteName(F, NONE) };
		case 9:
			return { NoteName(F, SHARP), NoteName(G, FLAT) };
		case 10:
			return { NoteName(G, NONE) };
		case 11:
			return { NoteName(G, SHARP), NoteName(A, FLAT) };
		default:
			break;
	}
}
