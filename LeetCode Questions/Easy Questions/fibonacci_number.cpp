// Problem - fibonacci Number (509) - LeetCode
// Time Complexity: O(n)
// Space Complexity: O(n)

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
    cout << "Enter a number: ";
    cin >> n;

    int result = fibonacci(n);
    cout << "Fibonacci of " << n << " is: " << result << endl;

    return 0;
}