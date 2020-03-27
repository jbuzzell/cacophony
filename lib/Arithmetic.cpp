#include "Arithmetic.h"

//https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


//https://www.tutorialspoint.com/find-closest-number-in-array-in-cplusplus
int getNearest(int x, int y, int target) {
    if (target - x >= y - target)
        return y;
    else
        return x;
}
int getNearestElement(std::vector<int> arr, int n, int target) {
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];
    int left = 0, right = n, mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (target < arr[mid]) {
            if (mid > 0 && target > arr[mid - 1])
                return getNearest(arr[mid - 1], arr[mid], target);
            right = mid;
        }
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getNearest(arr[mid], arr[mid + 1], target);
            left = mid + 1;
        }
    }
    return arr[mid];
}

//https://stackoverflow.com/questions/4229870/c-algorithm-to-calculate-least-common-multiple-for-multiple-numbers
int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

