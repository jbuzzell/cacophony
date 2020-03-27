#ifndef INTERVAL_H
#define INVERVAL_H

#include "Note.h"

class Interval {

public:

	Interval(Note one = 0, Note two = 0);

	int numerator;
	int denominator;
	int dissonance;

	int getDissonance();
	static int getDissonance(Note one, Note two);

private:

	void setDissonance();
	void setNumeratorDenominator(Note one, Note two);

};

#endif // !INTERVAL_H