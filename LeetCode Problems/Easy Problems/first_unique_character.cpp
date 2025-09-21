// Problem - First Unique Character in a string (387) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }
            m[s[i]]++;
            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};

int main() {
    Solution sol;

    string s = "leetcode";
    int index = sol.firstUniqChar(s);

    if (index == -1) {
        cout << "No unique character found." << endl;
    } else {
        cout << "First unique character is '" << s[index] 
             << "' at index " << index << endl;
    }

    return 0;
}