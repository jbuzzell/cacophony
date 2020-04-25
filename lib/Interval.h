#ifndef INTERVAL_H
#define INTERVAL_H

#include "Note.h"

/*
------------------------------------------------------------------------------------------------
- INTERVAL: a class containing dissonance information for two given notes and methods for 
-	calculating dissonance
-	
-	members:
-		- numerator: the numerator of the just interval
-		- denominator: the denominator of the just interval
-		- dissonance: the dissonance of the just interval, calculated by adding num + den
-
-	methods:
-		- getDissonance(): get dissonance of Interval object
-		- Interval::getDissonance(): get dissonance of the interval between two Notes
-		- setDissonance(): setter for member dissonance
-		- setNumeratorDenominator(): setter for numerator and denominator
------------------------------------------------------------------------------------------------
*/
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