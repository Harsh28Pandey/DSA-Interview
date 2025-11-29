// Problem - Append Characters to String to make Subsequence (2486) - LeetCOde
// Time Complexity - O(m + n)
// Space Complexity - O(1)

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;

        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                j = j + 1;
            }
            i = i + 1;
        }
        return t.size() - j;
    }
};