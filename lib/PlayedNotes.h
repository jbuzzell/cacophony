#ifndef PLAYED_NOTES_H_
#define PLAYED_NOTES_H_

#include <vector>
#include <algorithm>
#include "Note.h"

using namespace std;

/*
------------------------------------------------------------------------------------------------
- PLAYEDNOTES: a class initially meant to provide abstraction between persistent storage of
-	note data and the Teensy linker such that vectors could be snuck by without compile error.
-	now provides persistent storage of notes, as well as handling duplicate prevention, note
-	tracking, and the note generation algorithm.
-
-	members:
-		- mNotes: a vector containing all played notes
-		- mNumNotes: the number of notes
-
-	methods:
-		- add(): adds a note to mNotes, ignoring duplicates
-		- findLowestOctave(): searches the list of played notes to see what the lowest octave
-			that the player is playing in is
-		- suggestNote(): algorithmically generate a new note
-		- access operator: accesses an element of mNotes
------------------------------------------------------------------------------------------------
*/
class PlayedNotes {

public:

	PlayedNotes();

	vector<Note> mNotes;
	int mNumNotes;

	void add(Note n);
	int findLowestOctave();
	Note suggestNote();
	Note& operator[](int n);

};

#endif // !PLAYED_NOTES_H_
