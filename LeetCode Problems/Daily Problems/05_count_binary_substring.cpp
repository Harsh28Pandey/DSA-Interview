// Problem - Count Binary substring (696) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0, prev = 0, curr = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                curr++;
            } else {
                ans += min(prev,curr);
                prev = curr;
                curr = 1;
            }
        }
        ans += min(prev,curr);
        return ans;
    }
};