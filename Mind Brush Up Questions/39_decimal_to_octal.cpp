//? decimal to octal conversion

#include<iostream>
using namespace std;

int decimalToOctal(int n) {
    int ans = 0, pow = 1;
    while(n > 0) {
        int rem = n % 8;
        n /= 8;
        ans += rem * pow;
        pow *= 10;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the decimal number: ";
    cin >> n;
    int result = decimalToOctal(n);
    cout << "Octal number: " << result;
    return 0;
}