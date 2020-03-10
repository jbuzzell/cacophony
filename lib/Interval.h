#ifndef INTERVAL_H
#define INVERVAL_H

#include "Note.h"

class Interval {

public:

	Interval(Note one, Note two);

	int numerator;
	int denominator;
	int dissonance;

private:

	void setDissonance();

};

#endif // !INTERVAL_H