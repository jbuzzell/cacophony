#include "Scale.h"
#include "Note.h"
#include <iostream>

Scale::Scale(vector<Note> basis, int notes = 8) : mNumNotes(notes), mNotes(new Note[notes]) {
	
	// this is mostly pseudocode for now

	// basis is the existing notes having been read in from the player's signal
	// notes are sorted, in order, and ideally sequential
	vector<Note> scale = basis;

	while (scale.size != notes) {

		Note root = scale[0];
		Note last = scale.back;

		/*
		 *	use loop to determine next viable note in scale
		 *	remain within the octave determined by scale root
		 *	fill in the scale up to the value of notes
		 */

	}

}

double Scale::getHarmonyCoefficient() {

	double score = 0;
	int comparisons = 0;

	for (int i = 0; i < mNotes.size--; i++) {
		for (int j = i++; j < mNotes.size; j++) {
			score += getHarmonyScore(mNotes[i], mNotes[j]);
			comparisons++;
		}
	}

	return score / comparisons;

}

double Scale::getHarmonyScore(Note one, Note two) {
	
	// todo: make this a more intuitive metric
	div = __gcd(int(one.getFundamental), int(two.getFundamental));

	return (int(one.getFundamental) / div) + (int(two.getFundamental) / div);

}

