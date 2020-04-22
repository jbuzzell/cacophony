#ifndef PLAYED_NOTES_H_
#define PLAYED_NOTES_H_

#include <vector>
#include <algorithm>
#include "Note.h"

using namespace std;

class PlayedNotes {

public:

	PlayedNotes();

	vector<Note> mNotes;
	int mNumNotes;

	void add(Note n);
	Note suggestNote();
	Note& operator[](int n);

};

#endif // !PLAYED_NOTES_H_
