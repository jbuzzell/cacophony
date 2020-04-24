#include "Note.h"
#include <math.h>

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
