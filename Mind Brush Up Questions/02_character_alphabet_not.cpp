//? A character is an alphabet or not

#include<iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter the character: ";
    cin >> c;
    if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
        cout << "Character " << c << " is an alphabet" << endl;
    } else {
        cout << "Character " << c << " is not an alphabet" << endl;
    }
    return 0;
}