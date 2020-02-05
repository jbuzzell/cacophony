#include "Arithmetic.h"

//https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
