#ifndef NOTE_NAME_H
#define NOTE_NAME_H

const enum class NoteLetter { A, B, C, D, E, F, G };
const enum class NoteSymbol { FLAT, SHARP, NONE };

struct NoteName {
public:

	NoteName(NoteLetter letter, NoteSymbol symbol);

	NoteLetter mLetter;
	NoteSymbol mSymbol;

};

#endif // !NOTE_NAME_H
