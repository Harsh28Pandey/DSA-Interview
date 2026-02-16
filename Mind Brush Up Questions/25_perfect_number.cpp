//? perfect number or not

#include<iostream>
using namespace std;

void perfectNumber(int n) {
    int sum = 0;
    for(int i = 1; i < n / 2; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }
    if(sum == n) {
        cout << "Number is perfect";
    } else {
        cout << "Number is not perfect";
    }
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    perfectNumber(n);
    return 0;
}