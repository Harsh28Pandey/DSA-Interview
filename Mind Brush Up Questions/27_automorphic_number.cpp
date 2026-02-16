//? automorphic number or not

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int temp = n;
    int square = n * n;
    int count = 0;
    while(n != 0) {
        count++;
        n /= 10;
    }
    int rem,sum = 0;
    for(int i = 0; i < count; i++) {
        rem = square % 10;
        sum += rem * pow(10,i);
        square /= 10;
    }
    if(temp == sum) {
        cout << "Automorphic number";
    } else {
        cout << "Not automorphic number";
    }
    return 0;
}