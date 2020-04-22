#ifndef NOTE_H
#define NOTE_H

#include <vector>
#include "NoteName.h"

using namespace std;

class Note {

public:

	Note(double fundamental, int cmd = 1, int vel = 0x45);
	int mChannel, mVel;
	int mNote;
	double mFundamental;
	vector<NoteName> mNoteNames;

private:

	double getFundamental();
	int getNoteFromFundamental();
	int getNoteFromFundamental(double);
	void getNoteNamesFromMIDINumber(vector<NoteName>&, int);

};

#endif // !NOTE_H
