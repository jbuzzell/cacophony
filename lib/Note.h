#ifndef NOTE_H
#define NOTE_H

#include <vector>
#include "NoteName.h"

class Note {

public:

	Note(double fundamental, int cmd = 0x90, int vel = 0x45);
	int mChannel, mVel;
	int mNote;
	double mFundamental;
	std::vector<NoteName> mNoteNames;

private:

	double getFundamental();
	int getNoteFromFundamental();
	int getNoteFromFundamental(double);
	std::vector<NoteName> getNoteNamesFromMIDINumber(int);

};

#endif // !NOTE_H
