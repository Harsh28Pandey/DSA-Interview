#include<iostream>
using namespace std;

void printDigits(int n) {
    while(n != 0) {
        int digit = n % 10; // get the last digit
        cout << digit << " "; // print the digit
        n /= 10; // remove the last digit
    }
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Digits in reverse order: ";
    printDigits(number);
    cout << endl;
    return 0;
}