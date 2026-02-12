// Problem - Find the Difference (389) - LeetCode
// Time Complexity - O(n)

class Solution {
public:
    char findTheDifference(string s, string t) {
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
            result ^= s[i] ^ t[i];
        }
        result ^= t[t.size() - 1];
        return result;
    }
};