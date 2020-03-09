#ifndef NOTE_H
#define NOTE_H

#include <vector>

class Note {

public:

	Note(double fundamental, int cmd = 0x90, int vel = 0x45);
	int mChannel, mVel;
	int mNote;
	double mFundamental;
	NoteName mNoteName;

private:

	double getFundamental();
	int getNoteFromFundamental();
	int getNoteFromFundamental(double);
	std::vector<NoteName> getNoteNamesFromMIDINumber(int);

};

const enum NoteLetter { A, B, C, D, E, F, G };
const enum NoteSymbol { FLAT, SHARP, NONE };

struct NoteName {
public:

	NoteName(NoteLetter letter, NoteSymbol symbol) : mLetter(letter), mSymbol(symbol) {}

	NoteLetter mLetter;
	NoteSymbol mSymbol;

};

#endif // !NOTE_H
