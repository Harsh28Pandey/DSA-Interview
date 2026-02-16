//? prime number or not

#include<iostream>
using namespace std;

int isPrime(int n) {
    if(n == 0 || n == 1) {
        return false;
    }
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int result = isPrime(n);
    cout << result;
    return 0;
}