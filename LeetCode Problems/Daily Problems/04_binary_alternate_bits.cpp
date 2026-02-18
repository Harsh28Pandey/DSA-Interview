// Problem - Binary Number with Alternating Bits (693) - LeetCode
// Time Complexity - O(log n)
// Space Complexity - O(log n)

class Solution {
public:
    string binaryNumber(int n) {
        string ans = "";
        if(n == 0) {
            return "0";
        }
        while(n > 0) {
            int rem = n % 2;
            ans += char(rem + '0');
            n /= 2;
        }
        return ans;
    }
    bool hasAlternatingBits(int n) {
        string res = binaryNumber(n);
        for(int i = 0; i < res.size() - 1; i++) {
            if(res[i] == res[i + 1]) {
                return false;
            }
        }
        return true;
    }
};