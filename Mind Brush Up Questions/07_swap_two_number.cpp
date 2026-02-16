//? Swap two numbers without third variable

#include<iostream>
using namespace std;

void swap(int &a,int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int a, b;
    cout << "Enter the first number a: ";
    cin >> a;
    cout << "Enter the second number b: ";
    cin >> b;
    cout << "Before swapping: " << a << " " << b << endl;
    swap(a,b);
    cout << "After swapping: " << a << " " << b << endl;
    return 0;
}