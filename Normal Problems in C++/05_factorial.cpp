#include<iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if(n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = factorial(n);
    cout << "The factorial of " << n << " is: " << result << endl;

    return 0;
}