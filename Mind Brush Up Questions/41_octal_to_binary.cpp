//? octal to binary

#include <iostream>
#include <cmath>
using namespace std;

int octal_decimal(int n) {
    int i = 0;
    int sum = 0;
    while (n > 0) { //* octal to decimal 
        // int rem = n%10;
        sum = sum + (n % 10) * (int)(round(pow(8, i)));
        n = n / 10;
        i++;
    }
    return sum;
}

int decimal_binary(int n) { //* devimal to binary
    int i = 0;
    int sum = 0;
    while (n > 0) {
        // int rem = n%10;
        sum = sum + (n % 2) * (int)(round(pow(10, i)));
        n = n / 2;
        i++;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the octal number : ";
    cin >> n;
    int deci = octal_decimal(n);    //* convert octal to decimal
    int oct = decimal_binary(deci); //* decimal to binary
    cout << "result is : " << oct << endl;
}