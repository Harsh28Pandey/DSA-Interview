//? binary to decimal conversion

#include<iostream>
using namespace std;

int binaryToDecimal(int n) {
    int ans = 0 , pow = 1;
    while(n > 0) {
        int rem = n % 10;
        n /= 10;
        ans += rem * pow;
        pow *= 2;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the binary number: ";
    cin >> n;
    int result = binaryToDecimal(n);
    cout << "Decimal number: " << result;
    return 0;
}