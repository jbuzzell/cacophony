#include "NoteName.h"

NoteName::NoteName(NoteLetter letter, NoteSymbol symbol) : mLetter(letter), mSymbol(symbol) {}

string NoteName::printName()
{
	string out = "";

	switch (mLetter) {
		case NoteLetter::A:
			out += "A";
			break;
		case NoteLetter::B:
			out += "B";
			break;
		case NoteLetter::C:
			out += "C";
			break;
		case NoteLetter::D:
			out += "D";
			break;
		case NoteLetter::E:
			out += "E";
			break;
		case NoteLetter::F:
			out += "F";
			break;
		case NoteLetter::G:
			out += "G";
	}

	switch (mSymbol) {
		case NoteSymbol::FLAT:
			out += "b";
			break;
		case NoteSymbol::SHARP:
			out += "#";
	}

	return out;
}
