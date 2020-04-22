#ifndef NOTE_NAME_H
#define NOTE_NAME_H

#include <string>

using namespace std;



enum class NoteLetter { A, B, C, D, E, F, G };
enum class NoteSymbol { FLAT, SHARP, NONE };

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
