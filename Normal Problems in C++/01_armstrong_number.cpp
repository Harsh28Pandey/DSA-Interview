#include<iostream>
using namespace std;

bool armstrongNumber(int n) {
    int copyN = n;
    int sumOfCubes = 0;
    while(n != 0) {
        int digit = n % 10; // get the last digit
        sumOfCubes += digit * digit * digit; // add the cube of the digit
        n /= 10; // remove the last digit
    }
    return sumOfCubes == copyN; // check if the sum of cubes equals the original number
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if(armstrongNumber(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }
    return 0;
}