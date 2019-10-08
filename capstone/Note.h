#ifndef NOTE_H
#define NOTE_H

class Note {

public:

	//Note(int note, int cmd, int vel);
	Note(double note, int cmd, int vel);
	int mCmd, mVel;
	int mNote;

	int getNoteFromFundamental(double);

};

#endif // !NOTE_H
