#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int n = s.length();
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
           s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            count++;
        }
    }

    cout << "Number of vowels in the string: " << count << endl;
    return 0;
}