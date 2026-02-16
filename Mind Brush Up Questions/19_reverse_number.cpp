//? reverse a given number

#include<iostream>
using namespace std;

int reverseNumber(int n) {
    int rev = 0;
    while(n > 0) {
        int rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    return rev;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int result = reverseNumber(n);
    cout << "Reversed number: " << result;
    return 0;
}