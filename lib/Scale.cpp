#include "Scale.h"

Scale::Scale(vector<Note> basis, int notes = 8) : mNumNotes(notes), mNotes(basis) {

	/*while (basis.size != notes) {

		Note root = basis[0];
		Note last = basis.back;

		/*
		 *	use loop to determine next viable note in scale
		 *	remain within the octave determined by scale root
		 *	fill in the scale up to the value of notes
		 *

	}*/

	for (Note i: basis) {
		cout << i.mNote << endl;
	}

}

double Scale::getHarmonyCoefficient() {

	double score = 0;
	int comparisons = 0;

	/*for (int i = 0; i < mNotes.size--; i++) {
		for (int j = i++; j < mNotes.size; j++) {
			score += getHarmonyScore(mNotes[i], mNotes[j]);
			comparisons++;
		}
	}
	*/
	return score / comparisons;

}

double Scale::getHarmonyScore(Note one, Note two) {
	
	// todo: make this a more intuitive metric
	int div = gcd(int(one.mFundamental), int(two.mFundamental));

	return (int(one.mFundamental) / div) + (int(two.mFundamental) / div);

}

