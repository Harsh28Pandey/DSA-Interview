// Problem - Longest Common Prefix (14) - LeetCode

#include<iostream>
#include<vector>
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

int main() {
    vector<string> strs;

    cout << "Enter number of strings: ";
    int n; 
    cin >> n;

    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    string result = longestCommonPrefix(strs);
    if (result.empty()) {
        cout << "No common prefix found.\n";
    } else {
        cout << "Longest common prefix: " << result << "\n";
    }

    return 0;
}