//? fibonacci number

#include <iostream>
using namespace std;

void fibo(int n)
{
    int n1 = 0;
    int n2 = 1;
    cout << n1 << " ";
    cout << n2 << " ";
    for (int i = 2; i < n; i++)
    {
        int temp = n1 + n2;
        n1 = n2;
        n2 = temp;
        cout << temp << " ";
    }
    // recursion
    // if(n>=1)
    // {
    //     return n;
    // }
    // return fibo(n-1)+fibo(n-2);
}

int main()
{
    int n;
    cout << "Enter the number  ";
    cin >> n;

    fibo(n);
}