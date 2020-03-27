#include "PlayedNotes.h"
#include <iostream>
#include "Interval.h"
#include "Arithmetic.h"

void PlayedNotes::add(Note n)
{
	mNotes.push_back(n);
	mNumNotes++;
}

Note PlayedNotes::suggestNote()
{
	std::vector<Note> candidates = {
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

	auto newEnd = std::remove_if(candidates.begin(), candidates.end(),
		[this](const Note& n) {
			for (Note note : mNotes) {
				if (((note.mNote - 9) % 12) == ((n.mNote - 9) % 12)) { return true; }
			}
			return false;
		}
	);
	candidates.erase(newEnd, candidates.end());

	std::vector<int> dissonanceVals = std::vector<int>(candidates.size());

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

	std::vector<int> dissonanceValsSorted = dissonanceVals;

	std::sort(dissonanceValsSorted.begin(), dissonanceValsSorted.end());

	int closest = getNearestElement(dissonanceValsSorted, candidates.size(), target);

	// TODO: scale for octaves

	return candidates[std::distance(dissonanceVals.begin(), std::find(dissonanceVals.begin(), dissonanceVals.end(), closest))];
}
