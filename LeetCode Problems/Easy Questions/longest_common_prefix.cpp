// Problem - Longest Common Prefix (14) - LeetCode

#include<iostream>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Start with the first string as the prefix
    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        // Shorten the prefix until it matches the start of strs[i]
        while (strs[i].find(prefix) != 0) {
            prefix.pop_back();
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}