// Problem - Power of Three (326) - LeetCode

#include<iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if (n <= 0) return false; // Negative and zero are not powers of three
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

int main() {
    int n = 27;
    cout << boolalpha << isPowerOfThree(n) << endl;
    return 0;
}