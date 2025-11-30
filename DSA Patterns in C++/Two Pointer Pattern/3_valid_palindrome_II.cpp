// Problem - Valid Plaindrome II (680) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            char left = s[i];
            char right = s[j];

            if(left != right) {
                return isPalindrome(i + 1, j, s) || isPalindrome(i, j - 1, s);
            }
            else {
                i = i + 1;
                j = j - 1;
            }
        }
        return true;
    }
};