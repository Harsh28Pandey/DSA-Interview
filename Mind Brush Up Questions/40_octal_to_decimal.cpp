//? octal to decimal

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the octal number : ";
    cin >> n;
    int i = 0;
    int sum = 0;
    while (n > 0) {
        // int rem = n%10;
        sum = sum + (n % 10) * (int)(round(pow(8, i)));
        n = n / 10;
        i++;
    }
    cout << "Decimal Number : " << sum;
    return 0;
}