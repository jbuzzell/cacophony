#ifndef SCALE_H
#define SCALE_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Note.h"
#include "Arithmetic.h"

using namespace std;

class Scale {

public:

	Scale(vector<Note> basis, int notes);

	int mNumNotes;
	vector<Note> mNotes;

private:

	double getHarmonyCoefficient();

	/*
	 *	pre: Notes to be compared
	 *	post: ratio of their base frequencies
	 *	purpose: score the harmony/dissonance of two given notes. the higher the number,
	 *				the more dissonant the note.
	 */

	double getHarmonyScore(Note one, Note two);

};

#endif // !SCALE_H
