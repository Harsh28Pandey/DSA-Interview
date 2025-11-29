// Strobogrammatic Number - Self
// Time Complexity - O(n)
// Space Complexity - O(1)

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isStrobogrammaticNumber(unordered_map<char, char> &mp, const string &s) {
    int i = 0;
    int j = s.length() - 1;

    while (i <= j) {
        char l = s[i];
        char r = s[j];

        // Check if l exists in map
        if (mp.find(l) != mp.end()) {
            if (mp[l] != r) {
                return false;
            } else {
                i++;
                j--;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "198861";

    unordered_map<char, char> mp;
    mp['0'] = '0';
    mp['1'] = '1';
    mp['8'] = '8';
    mp['6'] = '9';
    mp['9'] = '6';

    cout << (isStrobogrammaticNumber(mp, s) ? "true" : "false") << endl;

    return 0;
}