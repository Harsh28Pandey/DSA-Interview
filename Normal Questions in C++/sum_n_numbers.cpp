#include<iostream>
using namespace std;

int sumOfN(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if(n < 1) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int result = sumOfN(n);
    cout << "The sum of the first " << n << " natural numbers is: " << result << endl;

    return 0;
}