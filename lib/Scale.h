#ifndef SCALE_H
#define SCALE_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Note.h"
#include "Arithmetic.h"
#include <numeric>

using namespace std;

class Scale {

public:

	Scale(vector<Note> basis);

	/*
	 *	TODO: implement constructor for variable size scales:
	 *	Scale(vector<Note> basis, int notes);
	 */

	int mNumNotes;
	vector<Note> mNotes;

//private:

	double getHarmonyCoefficient();

	/*
	 *	pre: Notes to be compared
	 *	post: ratio of their base frequencies
	 *	purpose: score the harmony/dissonance of two given notes. the higher the number,
	 *				the more dissonant the note.
	 */

	int getDissonance(Note one, Note two);
	int getSize();

};

#endif // !SCALE_H
