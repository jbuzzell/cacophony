#include "Note.h"
#include <math.h>

Note::Note(double fundamental, int channel, int vel) : mChannel(channel), mVel(vel), mFundamental(fundamental) { 

	mNote = getNoteFromFundamental(fundamental); 
	mNoteNames = getNoteNamesFromMIDINumber(mNote);

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

	switch (midiNo % 12)
	{
		case 0:
			return { NoteName(NoteLetter::A, NoteSymbol::NONE) };
		case 1:
			return { NoteName(NoteLetter::A, NoteSymbol::SHARP), NoteName(NoteLetter::B, NoteSymbol::FLAT) };
		case 2:
			return { NoteName(NoteLetter::B, NoteSymbol::NONE) };
		case 3:
			return { NoteName(NoteLetter::C, NoteSymbol::NONE) };
		case 4:
			return { NoteName(NoteLetter::C, NoteSymbol::SHARP), NoteName(NoteLetter::D, NoteSymbol::FLAT) };
		case 5:
			return { NoteName(NoteLetter::D, NoteSymbol::NONE) };
		case 6:
			return { NoteName(NoteLetter::D, NoteSymbol::SHARP), NoteName(NoteLetter::E, NoteSymbol::FLAT) };
		case 7:
			return { NoteName(NoteLetter::E, NoteSymbol::NONE) };
		case 8:
			return { NoteName(NoteLetter::F, NoteSymbol::NONE) };
		case 9:
			return { NoteName(NoteLetter::F, NoteSymbol::SHARP), NoteName(NoteLetter::G,NoteSymbol::FLAT) };
		case 10:
			return { NoteName(NoteLetter::G, NoteSymbol::NONE) };
		case 11:
			return { NoteName(NoteLetter::G, NoteSymbol::SHARP), NoteName(NoteLetter::A, NoteSymbol::FLAT) };
		default:
			break;
	}
}
