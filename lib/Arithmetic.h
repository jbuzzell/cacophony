#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <vector>

using namespace std;

/*
------------------------------------------------------------------------------------------------
- ARITHMETIC: basic math functions C++ doesn't offer. some of these are replacements for std::
-	functions that the Teensy linker complains about. most of them are from the internet.
------------------------------------------------------------------------------------------------
*/
int absVal(int x);
int gcd(int a, int b);
int getNearest(int x, int y, int target);
int getNearestElement(vector<int> arr, int n, int target);
int lcm(int a, int b);

#endif // !ARITHMETIC_H
