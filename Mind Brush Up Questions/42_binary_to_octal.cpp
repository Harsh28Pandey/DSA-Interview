//? binary to octal

#include <iostream>
#include <cmath>
using namespace std;

int binary_decimal(int n) //* binary to decimal number
{
    int i = 0;
    int sum = 0;
    while (n > 0)
    {
        // int rem = n%10;
        sum = sum + (n % 10) * (int)(round(pow(2, i)));
        n = n / 10;
        i++;
    }
    return sum;
}

int decimal_octal(int n) //* decimal to octal number
{
    int i = 0;
    int sum = 0;
    while (n > 0)
    {
        // int rem = n%10;
        sum = sum + (n % 8) * (int)(round(pow(10, i)));
        n = n / 8;
        i++;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the decimal number : ";
    cin >> n;
    int deci = binary_decimal(n);  //* convert binary to decimal
    int oct = decimal_octal(deci); //* decimal to octal
    cout << "result is : " << oct << endl;
}