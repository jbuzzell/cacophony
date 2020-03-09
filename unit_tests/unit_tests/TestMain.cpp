#include "../../lib/Note.h"
#include "pch.h"
#include "gtest/gtest.h"
#include "NoteTest.h"
#include <iostream>

int main() {
	NoteTest n = NoteTest();

	for (std::vector<std::map<double, double>>::const_iterator i = n.noteValues.begin(); i != n.noteValues.end(); ++i)
		for (auto elem : *i){
			std::cout << elem.first << " " << elem.second << std::endl;
		}
}