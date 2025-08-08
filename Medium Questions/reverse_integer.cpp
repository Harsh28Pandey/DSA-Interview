// Problem - Reverse Integer (7) - LeetCode

#include<iostream>
#include<limits.h>
#include<cmath>
using namespace std;

int reverseInteger(int n) {
    int revNum = 0;
    while(n != 0) {
        int digit = n % 10;
        if(revNum > INT_MAX / 10 || revNum < INT_MIN / 10) {
            return 0; // Handle overflow
        }
        revNum = revNum * 10 + digit;
        n /= 10;
    }
    return revNum;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    int reversed = reverseInteger(n);
    cout << "Reversed integer: " << reversed << endl;
    return 0;
}