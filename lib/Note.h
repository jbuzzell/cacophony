#ifndef NOTE_H
#define NOTE_H

#include <vector>
#include "NoteName.h"

using namespace std;

/*
------------------------------------------------------------------------------------------------
- NOTE: a data class used for storage and management of MIDI notes
-
-	members:
-		- mChannel: the MIDI channel to send signals over
-		- mVel: the velocity of the MIDI note
-		- mNote: the pitch of the note
-		- mFundamental: the fundamental frequency of the note
-
-	methods:
-		- Note::getFundamental(): a static function for use outside of the class. returns the 
-			fundamental frequency of a given MIDI note value
-		- getNoteFromFundamental(): determines MIDI note from a given fundamental frequency
-		- getNoteNamesFromMIDINumber(): returns a list of NoteNames for a given MIDI note 
-			number
------------------------------------------------------------------------------------------------
*/
class Note {

public:

	Note(double fundamental, int cmd = 1, int vel = 0x45);
	int mChannel, mVel;
	int mNote;
	double mFundamental;
	vector<NoteName> mNoteNames;

	static double getFundamental(int);

private:

	int getNoteFromFundamental();
	int getNoteFromFundamental(double);
	void getNoteNamesFromMIDINumber(vector<NoteName>&, int);

};

#endif // !NOTE_H
