#ifndef NOTE_NAME_H
#define NOTE_NAME_H

#include <string>

using namespace std;


// enums representing letters and symbols
enum class NoteLetter { A, B, C, D, E, F, G };
enum class NoteSymbol { FLAT, SHARP, NONE };

/*
------------------------------------------------------------------------------------------------
- NOTENAME: a basic struct representing linguistic representations of musical notes
-	e.g. A, Bb, C#
-
-	members:
-		- mLetter: the letter representing the note
-		- mSymbol: the symbol representing the note
-
-	methods:
-		- printName(): return a string value of the note
-		- equality operator
------------------------------------------------------------------------------------------------
*/
struct NoteName {
public:

	NoteName(NoteLetter letter, NoteSymbol symbol);

	NoteLetter mLetter;
	NoteSymbol mSymbol;

	string printName();

	bool operator==(const NoteName& other) const
	{
		return (int)mLetter == (int)other.mSymbol &&
			(int)mSymbol == (int)other.mSymbol;
	}

};

#endif // !NOTE_NAME_H
