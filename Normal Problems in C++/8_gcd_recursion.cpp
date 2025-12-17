// gcd (greatest common divisor) of two numbers

#include<iostream>
using namespace std;

int gcdRecursion(int a, int b) {
    if(b == 0) {
        return a; // base case: if b is 0, return a
    }
    return gcdRecursion(b, a % b); // recursive case: call gcd with b and remainder of a divided by b
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int result = gcdRecursion(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    return 0;
}