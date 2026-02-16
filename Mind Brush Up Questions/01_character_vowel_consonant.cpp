//? A character is a vowel or consonant

#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter the character: ";
    cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        cout << "Character " << c << " is a vowel" << endl;
    } else {
        cout << "Character " << c << " is a consonant" << endl;
    }
    return 0;
}