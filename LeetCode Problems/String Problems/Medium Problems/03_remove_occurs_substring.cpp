// Problem - Remove All Occurrences of a Substring (1910) - LeetCode

#include<iostream>
#include<string>
using namespace std;

string removeOccurances(string s, string part) {
    while(s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << "Remainning Substring is: " << removeOccurances(s, part) << endl; // Output: "dab"
    return 0;
}