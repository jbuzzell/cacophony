#include "PlayedNotes.h"
#include <iostream>
#include "Interval.h"
#include "Arithmetic.h"

PlayedNotes::PlayedNotes(){ mNumNotes = 0; }

void PlayedNotes::add(Note n)
{
	// if new note does not exist in list, add it to the list
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
	// a list of all possible notes from A to G# at an arbitrary octave
	// the algorithm will select a note from this list and return it
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

	// remove existing notes from candidacy
	candidates.erase(remove_if(candidates.begin(), candidates.end(),
		[this](const Note& n) {
			for (Note note : mNotes) {
				if (((note.mNote - 9) % 12) == ((n.mNote - 9) % 12)) { return true; }
			}
			return false;
		}
	), candidates.end());

	// create a vector to calculate the average dissonance of all notes in mNotes if candidate is added
	vector<int> dissonanceVals(candidates.size(), 0);

	// calculates average dissonance for all candidates 
	for (int i = 0; i < candidates.size(); i++) {
		int tmp = 0;
		for_each(mNotes.begin(), mNotes.end(),
			[&](const Note& note) {
				tmp += Interval::getDissonance(candidates[i], note);
			}
		);
		dissonanceVals[i] = tmp / mNumNotes;
	}	

	// determine the average dissonance of the current mNotes
	// the algorithm will try to match this value as closely as it can
	int target = 0;
	for (int i = 0; i < mNumNotes - 1; i++) {
		for (int j = 1; j < mNumNotes; j++) {
			target += Interval::getDissonance(mNotes[i], mNotes[j]);
		}
	}
	target /= mNumNotes;

	// sort all dissonance averages such that we can search for the closest match
	vector<int> dissonanceValsSorted(dissonanceVals.begin(), dissonanceVals.end());

	sort(dissonanceValsSorted.begin(), dissonanceValsSorted.end());

	// find the closest match
	int closest = getNearestElement(dissonanceValsSorted, candidates.size(), target);

	// get the note with the closest match dissonance value
	Note tmp = candidates[distance(dissonanceVals.begin(), find(dissonanceVals.begin(), dissonanceVals.end(), closest))];

	// return the note, scaled on the octave the user is playing in
	return Note(Note::getFundamental(((tmp.mNote - 9.0) * findLowestOctave()) + 9.0));
}

Note& PlayedNotes::operator[](int n)
{
	return mNotes[n];
}
