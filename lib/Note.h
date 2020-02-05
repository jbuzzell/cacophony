#ifndef NOTE_H
#define NOTE_H

class Note {

public:

	Note(double fundamental, int cmd = 0x90, int vel = 0x45);
	int mChannel, mVel;
	int mNote;
	double mFundamental;

private:

	double getFundamental();
	int getNoteFromFundamental();
	int getNoteFromFundamental(double);

};

#endif // !NOTE_H
