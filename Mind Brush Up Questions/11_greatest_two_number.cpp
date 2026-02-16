//? Greatest of two number

#include<iostream>
using namespace std;

int main() {
    int a,b;
    cout << "Enter the first number a: ";
    cin >> a;
    cout << "Enter the second number b: ";
    cin >> b;
    if(a > b) {
        cout << "a is greater";
    } else {
        cout << "b is greater";
    }
    return 0;
}