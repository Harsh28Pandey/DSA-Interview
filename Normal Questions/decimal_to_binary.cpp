#include<iostream>
using namespace std;

int decimalToBinary(int decimal) {
    int ans = 0, pow = 1;
    while(decimal > 0) {
        int rem = decimal % 2;
        decimal /= 2;
        ans += rem * pow;
        pow *= 10;
    }
    return ans;
}

int main() {
    int decimal;
    cout << "Enter a non-negative integer: ";
    cin >> decimal;

    if(decimal < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    int binary = decimalToBinary(decimal);
    cout << "The binary representation of " << decimal << " is: " << binary << endl;

    return 0;
}