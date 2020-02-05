#include "Note.h"
#include <math.h>

Note::Note(double fundamental, int channel, int vel) : mChannel(channel), mVel(vel), mFundamental(fundamental) { mNote = getNoteFromFundamental(fundamental); };

double Note::getFundamental() {

	return 12 * log2(mNote / 440.0) + 69;

}

int Note::getNoteFromFundamental() {

	return round(69.0 + (12.0 * log2(mFundamental / 440.0)));

}

int Note::getNoteFromFundamental(double f) {

	return round(69.0 + (12.0 * log2(f / 440.0)));

}
