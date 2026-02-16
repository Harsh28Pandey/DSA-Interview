//? Greatest of three numbers

#include<iostream>
using namespace std;

int main() {
    int a,b,c;
    cout << "Enter the first number a: ";
    cin >> a;
    cout << "Enter the second number b: ";
    cin >> b;
    cout << "Enter the third number c: ";
    cin >> c;
    if(a > b && a > c) {
        cout << "a is greater";
    } else if(b > a && b > c) {
        cout << "b is greater";
    } else {
        cout << "c is greater";
    }
    return 0;
}