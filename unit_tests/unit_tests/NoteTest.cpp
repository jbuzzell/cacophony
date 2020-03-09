#include "gtest/gtest.h"
#include "NoteTest.h"
#include <vector>
#include <fstream>
#include <stdexcept>

NoteTest::NoteTest() {
	std::ifstream in("note_data.csv");
	if (!in) {
		throw std::runtime_error("Could not open \"note.csv\"");
	}

	std::string line;
	while (std::getline(in, line)) {
		std::istringstream s(line);
		std::string field;
		std::vector<double> noteData = std::vector<double>();

		while (std::getline(s, field, ',')) {
			noteData.push_back(stod(field));
		}

		noteValues.push_back(std::map<double, double>({ noteData[0], noteData[1] }));
	}
}