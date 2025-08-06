#include<iostream>
using namespace std;

int sumOfDigits(int num) {
    int digitSum = 0;
    while(num > 0) {
        int lastDigit = num % 10;
        num = num / 10;
        digitSum += lastDigit;
    }
    return digitSum;
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if(num < 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int result = sumOfDigits(num);
    cout << "The sum of the digits of " << num << " is: " << result << endl;

    return 0;
}