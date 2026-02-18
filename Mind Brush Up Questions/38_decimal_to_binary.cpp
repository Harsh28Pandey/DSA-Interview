//? decimal to binary conversion

#include<iostream>
using namespace std;

int decimalToBinary(int n) {
    int ans = 0, pow = 1;
    while(n > 0) {
        int rem = n % 2;
        n /= 2;
        ans += rem * pow;
        pow *= 10;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the decimal number: ";
    cin >> n;
    int result = decimalToBinary(n);
    cout << "Binary number: " << result;
    return 0;
}