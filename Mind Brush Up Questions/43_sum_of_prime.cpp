//? check the number is the sum of two prime number

#include <iostream>
using namespace std;

bool isprime(int n)
{

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    bool found = false;
    int prime, prime1;
    for (int i = 2; i <= n / 2; i++)
    {
        if (isprime(i) && isprime(n - i))
        {
            found = true;
            prime = i;
            prime1 = n - i;
            break;
        }
    }

    if (found == true)
    {
        cout << "Given number is the sum of two prime number." << endl;
        cout << "Pair of prime number : " << prime << " + " << prime1 << endl;
    }
    else
    {
        cout << " Given number is not the sum of prime number ";
    }
}