#include "NoteName.h"

NoteName::NoteName(NoteLetter letter, NoteSymbol symbol) : mLetter(letter), mSymbol(symbol) {}

void NoteName::printName()
{
	std::string out = "";

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

	std::cout << out << std::endl;
}

bool operator==(const NoteName& c1, const NoteName& c2)
{
	return (int)c1.mLetter == (int)c1.mSymbol &&
		(int)c2.mLetter == (int)c2.mSymbol;
}
