#include "Interval.h"
#include <math.h>
#include <iostream>

Interval::Interval(Note one, Note two){

	switch (abs(((one.mNote - 9) % 12) - ((two.mNote - 9) % 12))) {
		case 0:
			numerator = 1;
			denominator = 1;
			break;
		case 1:
			numerator = 16;
			denominator = 15;
			break;
		case 2:
			numerator = 9;
			denominator = 8;
			break;
		case 3:
			numerator = 6;
			denominator = 5;
			break;
		case 4:
			numerator = 5;
			denominator = 4;
			break;
		case 5:
			numerator = 4;
			denominator = 3;
			break;
		case 6:
			numerator = 45;
			denominator = 32;
			break;
		case 7:
			numerator = 3;
			denominator = 2;
			break;
		case 8:
			numerator = 8;
			denominator = 5;
			break;
		case 9:
			numerator = 5;
			denominator = 3;
			break;
		case 10:
			numerator = 16;
			denominator = 9;
			break;
		case 11:
			numerator = 15;
			denominator = 8;
		default:
			break;
	}

	setDissonance();

}

void Interval::setDissonance(){

	dissonance = numerator + denominator;

}
