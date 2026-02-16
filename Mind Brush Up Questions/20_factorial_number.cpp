//? factorial of a number

#include<iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return n *factorial(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int result = factorial(n);
    cout << "Factorial of number: " << result;
    return 0;
}