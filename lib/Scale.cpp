#include "Scale.h"

Scale::Scale(vector<Note> basis, int notes = 7) : mNumNotes(notes), mNotes(basis) {



}

// fuck all this shit yo
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

