// Problem - Longest Substring Without Repeating Characters (3) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n) 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maximum = 0;
        int i = 0, j = 0;
        set<char> st;

        while (j < s.length()) {
            char c = s[j];   // C++ uses s[j], not charAt

            while (st.find(c) != st.end()) {
                st.erase(s[i]);   // remove character at i
                i++;
            }

            st.insert(c);
            maximum = max(maximum, j - i + 1);
            j++;
        }

        return maximum;
    }
};