// lcm (least / lowest common multiple) of two numbers

#include<iostream>
using namespace std;

int gcdRecursive(int a, int b) {
    if(b == 0) {
        return a; // base case: if b is 0, return a
    }
    return gcdRecursive(b, a % b); // recursive case: call gcd with b and remainder of a divided by b
}

int lcm(int a, int b) {
    int gcd = gcdRecursive(a,b);
    return (a * b) / gcd; // lcm is calculated using the formula: lcm(a, b) = (a * b) / gcd(a, b)
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int result = lcm(num1, num2);
    cout << "LCM of " << num1 << " and " << num2 << " is: " << result << endl;
    return 0;
}