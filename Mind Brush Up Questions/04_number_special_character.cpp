//? Number, uppercase, lowercase or special character

#include<iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter the character to check (Number,Uppercase,Lowercase,Special Character): ";
    cin >> c;
    if(c >= '0' && c <= '9') {
        cout << "Character " << c << " is a Number" << endl;
    } else if(c >= 'A' && c <= 'Z') {
        cout << "Character " << c << " is a Uppercase letter" << endl;
    } else if(c >= 'a' && c <= 'z') {
        cout << "Character " << c << " is a Lowercase letter" << endl;
    } else {
        cout << "Character " << c << " is a Special Character" << endl;
    }
    return 0;
}