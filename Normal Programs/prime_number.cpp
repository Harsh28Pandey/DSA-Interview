#include<iostream>
using namespace std;

void PrimeNumber(int n) {
    if (n < 2) {
        cout << "No prime numbers less than 2." << endl;
        return;
    }

    cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number to find all prime numbers up to that number: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    PrimeNumber(n);
    return 0;
}