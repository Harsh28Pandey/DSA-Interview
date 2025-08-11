// Problem - Palindrome Partitioning (131) - LeetCode
// Time Complexity - O(n * 2^n)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getAllPartitions(string s, vector<string> &partitions, vector<vector<string>> &ans) {
    if(s.size() == 0) {
        ans.push_back(partitions);
        return ;
    }
    for(int i = 0; i < s.size(); i++) {
        string part = s.substr(0,i + 1);
        if(isPalindrome(part)) {
            partitions.push_back(part);
            getAllPartitions(s.substr(i + 1),partitions,ans);
            partitions.pop_back();
        }
    }
}

bool isPalindrome(string s) {
    string s2 = s;
    reverse(s2.begin(),s2.end());
    return s == s2;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partitions;
    getAllPartitions(s,partitions,ans);
    return ans;
}

int main() {
    string str = "aab";
    vector<vector<string>> ans = partition(str);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}