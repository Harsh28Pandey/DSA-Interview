//? armstrong number or not

#include<iostream>
#include<cmath>
using namespace std;

int armstrongNumber(int n) {
    int sum = 1;
    int temp = n;
    while(n > 0) {
        int rem = n % 10;
        sum += pow(rem,3);
        n = n / 10;
    }
    if(sum == temp) {
        return 1;
    } else {
        return 0;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int result = armstrongNumber(n);
    cout << "Result: " << result;
    return 0;
}