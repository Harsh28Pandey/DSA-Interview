// Problem - Longest Substring Without Repeating Character (3) - LeetCode

#include<iostream>
#include <string>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<bool> count(256,0);
    int first = 0, second = 0, len = 0;
    while(second < s.size())
    {
        //repeating character
        while(count[s[second]])
        {
            count[s[first]] = 0;
            first ++;
        }
        count[s[second]] = 1;
        len = max(len,second - first + 1);
        second ++;
    }
    return len;
}

int main() {
    string input = "abcabcbb"; // You can change this to test other cases

    int result = lengthOfLongestSubstring(input);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}