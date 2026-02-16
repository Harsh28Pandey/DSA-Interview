//? Number of digits in an integer

#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int count = 0;
    while(n != 0) {
        int digit = n % 10;
        count++;
        n /= 10;
    }
    cout << "No. of digits: " << count;
    return 0;
}