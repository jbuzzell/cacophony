#include "PlayedNotes.h"
#include <iostream>
#include "Interval.h"
#include "Arithmetic.h"

PlayedNotes::PlayedNotes(){ mNumNotes = 0; }

void PlayedNotes::add(Note n)
{
	// if new note does not exist in list
	if (find_if(mNotes.begin(), mNotes.end(), 
		[&](const Note& it) {
			return ((it.mNote - 9) % 12) == ((n.mNote - 9) % 12); 
		}) == mNotes.end()) 
	{
		mNotes.push_back(n);
		mNumNotes++;
	}
}

int PlayedNotes::findLowestOctave()
{
	int lowest = 0;
	for (int i = 0; i < mNotes.size(); i++) {
		lowest = ((mNotes[i].mNote - 9) / 12);
	}
	return lowest;
}

Note PlayedNotes::suggestNote()
{
	vector<Note> candidates {
		Note(27.5),
		Note(29.14),
		Note(30.87),
		Note(32.7),
		Note(34.65),
		Note(36.71),
		Note(38.89),
		Note(41.2),
		Note(43.65),
		Note(46.25),
		Note(49),
		Note(51.91),
	};

	candidates.erase(remove_if(candidates.begin(), candidates.end(),
		[this](const Note& n) {
			for (Note note : mNotes) {
				if (((note.mNote - 9) % 12) == ((n.mNote - 9) % 12)) { return true; }
			}
			return false;
		}
	), candidates.end());

	vector<int> dissonanceVals(candidates.size(), 0);

	for (int i = 0; i < candidates.size(); i++) {
		int tmp = 0;
		for_each(mNotes.begin(), mNotes.end(),
			[&](const Note& note) {
				tmp += Interval::getDissonance(candidates[i], note);
			}
		);
		dissonanceVals[i] = tmp / mNumNotes;
	}	

	int target = 0;
	for (int i = 0; i < mNumNotes - 1; i++) {
		for (int j = 1; j < mNumNotes; j++) {
			target += Interval::getDissonance(mNotes[i], mNotes[j]);
		}
	}
	target /= mNumNotes;

	vector<int> dissonanceValsSorted(dissonanceVals.begin(), dissonanceVals.end());

	sort(dissonanceValsSorted.begin(), dissonanceValsSorted.end());

	int closest = getNearestElement(dissonanceValsSorted, candidates.size(), target);

	Note tmp = candidates[distance(dissonanceVals.begin(), find(dissonanceVals.begin(), dissonanceVals.end(), closest))];

	return Note(Note::getFundamental(((tmp.mNote - 9.0) * findLowestOctave()) + 9.0));
}

Note& PlayedNotes::operator[](int n)
{
	return mNotes[n];
}
