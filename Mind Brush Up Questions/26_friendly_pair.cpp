//? friendly pair or not (amicable or not)

#include<iostream>
using namespace std;

int sumOfDivisors(int n) {
    int sum = 0;
    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n1,n2;
    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter the second number: ";
    cin >> n2;
    int sum1 = sumOfDivisors(n1);
    int sum2 = sumOfDivisors(n2);
    if(sum1 == n2 && sum2 == n1) {
        cout << "Friendly pair";
    } else {
        cout << "Not friendly pair";
    }
    return 0;
}