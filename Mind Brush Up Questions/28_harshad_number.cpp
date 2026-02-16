//? harshad number or not

#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int sum = 0,temp = n;
    while(temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }
    if(n % sum == 0) {
        cout << "Harshad number";
    } else {
        cout << "Not harshad number";
    }
    return 0;
}