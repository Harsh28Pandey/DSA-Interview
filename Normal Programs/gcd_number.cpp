// gcd (greatest common divisor) of two numbers

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b; // replace a with remainder of a divided by b
        } else {
            b = b % a; // replace b with remainder of b divided by a
        }
    }
    if(a == 0) {
        return b; // if a is 0, return b
    } else {
        return a; // if b is 0, return a
    }
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int result = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    return 0;
}