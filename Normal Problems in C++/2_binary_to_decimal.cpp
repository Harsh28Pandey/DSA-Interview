#include<iostream>
using namespace std;

int binaryToDecimal(int binary) {
    int ans = 0, pow = 1;
    while(binary > 0) {
        int rem = binary % 10;
        ans += rem * pow;
        binary /= 10;
        pow *= 2;
    }
    return ans;
}

int main() {
    int binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    if(binary < 0) {
        cout << "Please enter a valid binary number." << endl;
        return 1;
    }

    int decimal = binaryToDecimal(binary);
    cout << "The decimal representation of " << binary << " is: " << decimal << endl;

    return 0;
}