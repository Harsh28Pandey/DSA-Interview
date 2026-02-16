//? Ascii value of a character

#include<iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter the character: ";
    cin >> c;
    cout << "ASCII value of character " << c << " is: " << int(c) << endl;
    return 0;
}