#ifndef NOTE_H
#define NOTE_H

class Note {

public:

	Note(double note, int cmd, int vel);
	int mCmd, mVel;
	int mNote;

	static enum noteNames = {
		A,
		A_S,
		B,
		C,
		C_S,
		D,
		D_S,
		E,
		F,
		F_S,
		G,
		G_S
	};

	double getFundamental();
	int getNoteFromFundamental(double);

};

#endif // !NOTE_H
