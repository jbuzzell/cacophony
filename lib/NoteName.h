#ifndef NOTE_NAME_H
#define NOTE_NAME_H

#include <string>
#include <iostream>

const enum class NoteLetter { A, B, C, D, E, F, G };
const enum class NoteSymbol { FLAT, SHARP, NONE };

struct NoteName {
public:

	NoteName(NoteLetter letter, NoteSymbol symbol);

	NoteLetter mLetter;
	NoteSymbol mSymbol;

	void printName();

	friend bool operator==(const NoteName& c1, const NoteName& c2);

};

#endif // !NOTE_NAME_H
