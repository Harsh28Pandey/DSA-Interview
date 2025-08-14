#include<iostream>
using namespace std;

int sum(int n) {
    if(n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter a number to calculate the sum of first n natural numbers: ";
    cin >> n;

    if (n < 1) {
        cout << "Please enter a positive integer." << endl;
    } else {
        cout << "Sum of first " << n << " natural numbers is " << sum(n) << endl;
    }

    return 0;
}