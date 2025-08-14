#include<iostream>
using namespace std;

int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the position of the Fibonacci number: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is: " << result << endl;

    return 0;
}