// Problem - Longest Repeating Character Replacement (424) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        int maxLength = 0;
        int maxCharacter = 0;
        int count[26];

        while(j < s.size()) {
            char c = s[j];
            count[c - 'A']++;
            maxCharacter = max(maxCharacter, count[c - 'A']);

            while((j - i + 1) - maxCharacter > k) {
                char d = s[i];
                count[d - 'A']--;
                i++;

                for(int l = 0; l < 26; l++) {
                    maxCharacter = max(maxCharacter, count[l]);
                }
            }

            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};