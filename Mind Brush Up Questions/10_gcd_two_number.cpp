//? GCD of two numbers

#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "enter the number  ";
    cin >> a;
    cin >> b;
    int gcd;
    int min = (a < b) ? a : b;
    for (int i = 1; i <= min; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    cout << gcd;
}