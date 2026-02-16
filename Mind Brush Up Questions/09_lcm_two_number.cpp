//? LCM of two numbers

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "enter the number  ";
    cin >> a;
    cin >> b;

    int max = (a > b) ? a : b;
    while (true)
    {
        if (max % a == 0 && max % b == 0)
        {
            cout << max;
            break;
        }
        max++;
    }
}
