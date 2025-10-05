// Problem - Palindrome Partitioning (131) - LeetCode
// Time Complexity - O(n * 2^n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if a string is a palindrome
bool isPalindrome(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

// Recursive helper function to get all palindrome partitions
void getAllPartitions(string s, vector<string>& partitions, vector<vector<string>>& ans) {
    if (s.size() == 0) {
        ans.push_back(partitions);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        string part = s.substr(0, i + 1);
        if (isPalindrome(part)) {
            partitions.push_back(part);
            getAllPartitions(s.substr(i + 1), partitions, ans);
            partitions.pop_back();
        }
    }
}

// Main partitioning function
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partitions;
    getAllPartitions(s, partitions, ans);
    return ans;
}

int main() {
    string str = "aab";
    vector<vector<string>> ans = partition(str);

    cout << "Palindrome partitions of \"" << str << "\":" << endl;
    for (const auto& vec : ans) {
        for (const auto& part : vec) {
            cout << part << " ";
        }
        cout << endl;
    }

    return 0;
}