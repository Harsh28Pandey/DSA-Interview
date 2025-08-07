// Problem - Valid Palindrome (125) - Leetcode

#include<iostream>
#include<string>
using namespace std;

bool isAlphaNumeric(char ch) {
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int start = 0, end = s.length() - 1;
    while(start < end) {
        if(!isAlphaNumeric(s[start])) {
            start++;
            continue;
        }
        if(!isAlphaNumeric(s[end])) {
            end--;
            continue;
        }
        if(tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    
    if(isPalindrome(s)) {
        cout << "The string is a valid palindrome." << endl;
    } else {
        cout << "The string is not a valid palindrome." << endl;
    }
    
    return 0;
}