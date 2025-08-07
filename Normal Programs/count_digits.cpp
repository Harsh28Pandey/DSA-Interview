#include<iostream>
using namespace std;

void countDigits(int n) {
    int count = 0;
    while(n != 0) {
        int digit = n % 10;
        count++;// increment count for each digit
        n /= 10; // remove the last digit
    }
    cout << "Number of digits: " << count << endl;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    countDigits(number);
    return 0;
}