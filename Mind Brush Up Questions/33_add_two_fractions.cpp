//? add two fractions

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, den1, num2, den2;

    cout << "Enter first fraction (numerator denominator): ";
    cin >> num1 >> den1;

    cout << "Enter second fraction (numerator denominator): ";
    cin >> num2 >> den2;

    int result_num = num1 * den2 + num2 * den1;
    int result_den = den1 * den2;

    int divisor = gcd(result_num, result_den);
    result_num /= divisor;
    result_den /= divisor;

    cout << "Sum = " << result_num << "/" << result_den << endl;

    return 0;
}