// Problem - Plaindrome Number (9) - LeetCode

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

bool isPalindrome(int n) {
    if(n < 0) {
        return false; // Negative numbers are not palindromes
    }
    int revNum = reverseInteger(n);
    return n == revNum;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    if(isPalindrome(n)) {
        cout << n << " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }
    return 0;
}