#include "CppUnitTest.h"
#include "/path/to/Note.h"
#include "/path/to/Note.cpp"
#include "/path/to/NoteName.h"
#include "/path/to/NoteName.cpp"
#include "/path/to/Arithmetic.h"
#include "/path/to/Arithmetic.cpp"
#include "/path/to/Interval.h"
#include "/path/to/Interval.cpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/tokenizer.hpp>

using namespace boost;

namespace Microsoft {
    namespace VisualStudio {
        namespace CppUnitTestFramework {

            template<> 
            static std::wstring ToString<std::vector<NoteName>>(const class std::vector<NoteName>& noteName) { 
                return L"NoteName"; 
            }

            namespace cacophonytests
            {

                std::vector<std::vector<std::string>> data;

                TEST_MODULE_INITIALIZE(CacophonyTestsInitialize)
                {
                    std::ifstream file("/path/to/data.csv");
                    if (!file.is_open()) return;

                    typedef tokenizer< escaped_list_separator<char> > Tokenizer;

                    std::string line;

                    while (getline(file, line)) {
                        Tokenizer tok(line);
                        std::vector<std::string> row;

                        for (std::string s : tok) {
                            row.push_back(s);
                        }

                        data.push_back(row);
                    }

                    data.pop_back();
                }

                TEST_CLASS(NoteTest){

                    public:
                        TEST_METHOD(TestMIDIToFundamental) {

                            for (std::vector<std::string> v : data) {
                                Note n = Note(stod(v[1]));
                                Assert::AreEqual(n.mNote, stoi(v[0]));
                            }

                        }

                        TEST_METHOD(TestNoteNames) {

                            for (std::vector<std::string> v : std::vector<std::vector<std::string>>(data.begin(), data.begin() + 11)) {
                                Note n = Note(stod(v[1]));
                                switch (n.mNote)
                                {
                                case 21:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::A, NoteSymbol::NONE)
                                    });
                                    break;
                                case 22:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::A, NoteSymbol::SHARP),
                                            NoteName(NoteLetter::B, NoteSymbol::FLAT)
                                    });
                                    break;
                                case 23:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::B, NoteSymbol::NONE)
                                    });
                                    break;
                                case 24:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::C, NoteSymbol::NONE)
                                    });
                                    break;
                                case 25:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::C, NoteSymbol::SHARP),
                                            NoteName(NoteLetter::D, NoteSymbol::FLAT)
                                    });
                                    break;
                                case 26:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::D, NoteSymbol::NONE)
                                    });
                                    break;
                                case 27:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::D, NoteSymbol::SHARP),
                                            NoteName(NoteLetter::E, NoteSymbol::FLAT)
                                    });
                                    break;
                                case 28:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::E, NoteSymbol::NONE)
                                    });
                                    break;
                                case 29:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::F, NoteSymbol::NONE)
                                    });
                                    break;
                                case 30:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::F, NoteSymbol::SHARP),
                                            NoteName(NoteLetter::G, NoteSymbol::FLAT)
                                    });
                                    break;
                                case 31:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::G, NoteSymbol::NONE)
                                    });
                                    break;
                                case 32:
                                    Assert::AreEqual(n.mNoteNames, std::vector<NoteName>{
                                        NoteName(NoteLetter::G, NoteSymbol::SHARP),
                                            NoteName(NoteLetter::A, NoteSymbol::FLAT)
                                    });
                                    break;
                                default:
                                    break;
                                }
                            }

                        }

                };

                TEST_CLASS(IntervalTest){

                    public:

                        TEST_METHOD(TestDissonance) {

                            for (std::vector<std::string> v : std::vector<std::vector<std::string>>(data.begin(), data.begin() + 11)) {
                                Note n = Note(27.5);
                                Note d = Note(stod(v[1]));
                                switch (stoi(v[0]))
                                {
                                case 21:
                                    Assert::AreEqual(2, Interval::getDissonance(n, d));
                                    break;
                                case 22:
                                    Assert::AreEqual(31, Interval::getDissonance(n, d));
                                    break;
                                case 23:
                                    Assert::AreEqual(17, Interval::getDissonance(n, d));
                                    break;
                                case 24:
                                    Assert::AreEqual(11, Interval::getDissonance(n, d));
                                    break;
                                case 25:
                                    Assert::AreEqual(9, Interval::getDissonance(n, d));
                                    break;
                                case 26:
                                    Assert::AreEqual(7, Interval::getDissonance(n, d));
                                    break;
                                case 27:
                                    Assert::AreEqual(77, Interval::getDissonance(n, d));
                                    break;
                                case 28:
                                    Assert::AreEqual(5, Interval::getDissonance(n, d));
                                    break;
                                case 29:
                                    Assert::AreEqual(13, Interval::getDissonance(n, d));
                                    break;
                                case 30:
                                    Assert::AreEqual(8, Interval::getDissonance(n, d));
                                    break;
                                case 31:
                                    Assert::AreEqual(25, Interval::getDissonance(n, d));
                                    break;
                                case 32:
                                    Assert::AreEqual(23, Interval::getDissonance(n, d));
                                    break;
                                default:
                                    break;
                                }
                            }

                        }

                        TEST_METHOD(TestNumDem) {

                            for (std::vector<std::string> v : std::vector<std::vector<std::string>>(data.begin(), data.begin() + 11)) {
                                Note n = Note(27.5);
                                Note d = Note(stod(v[1]));
                                Interval i = Interval(n, d);
                                switch (stoi(v[0]))
                                {
                                case 21:
                                    Assert::AreEqual(1, i.numerator);
                                    Assert::AreEqual(1, i.denominator);
                                    break;
                                case 22:
                                    Assert::AreEqual(16, i.numerator);
                                    Assert::AreEqual(15, i.denominator);
                                    break;
                                case 23:
                                    Assert::AreEqual(9, i.numerator);
                                    Assert::AreEqual(8, i.denominator);
                                    break;
                                case 24:
                                    Assert::AreEqual(6, i.numerator);
                                    Assert::AreEqual(5, i.denominator);
                                    break;
                                case 25:
                                    Assert::AreEqual(5, i.numerator);
                                    Assert::AreEqual(4, i.denominator);
                                    break;
                                case 26:
                                    Assert::AreEqual(4, i.numerator);
                                    Assert::AreEqual(3, i.denominator);
                                    break;
                                case 27:
                                    Assert::AreEqual(45, i.numerator);
                                    Assert::AreEqual(32, i.denominator);
                                    break;
                                case 28:
                                    Assert::AreEqual(3, i.numerator);
                                    Assert::AreEqual(2, i.denominator);
                                    break;
                                case 29:
                                    Assert::AreEqual(8, i.numerator);
                                    Assert::AreEqual(5, i.denominator);
                                    break;
                                case 30:
                                    Assert::AreEqual(5, i.numerator);
                                    Assert::AreEqual(3, i.denominator);
                                    break;
                                case 31:
                                    Assert::AreEqual(16, i.numerator);
                                    Assert::AreEqual(9, i.denominator);
                                    break;
                                case 32:
                                    Assert::AreEqual(15, i.numerator);
                                    Assert::AreEqual(8, i.denominator);
                                    break;
                                default:
                                    break;
                                }
                            }

                        }

                };
            }

        }
    }
}

