#ifndef PLAYED_NOTES_H_
#define PLAYED_NOTES_H_

#include <vector>
#include <algorithm>
#include "Note.h"

class PlayedNotes {

public:

	std::vector<Note> mNotes;
	int mNumNotes;

	void add(Note n);
	Note suggestNote();

};

#endif // !PLAYED_NOTES_H_
