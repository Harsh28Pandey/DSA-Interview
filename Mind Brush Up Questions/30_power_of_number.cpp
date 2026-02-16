//? power of a number

#include<iostream>
using namespace std;

int main() {
    int base;
    int exponent;
    long long sum = 1;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;
    for(int i = 0; i < exponent; i++) {
        sum *= base;
    }
    cout << "Power of number: " << sum;
    return 0;
}