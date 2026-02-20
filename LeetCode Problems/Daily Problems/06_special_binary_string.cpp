// Problem - Special Binary String (761) - LeetCode
// Time Complexity - O(n log n)
// Space complexity - O(n)

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> substring;
        int start = 0, count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1')
            count++;

            else 
            count--;

            if(count == 0) {
                string processed = makeLargestSpecial(s.substr(start + 1,i - start - 1));
                substring.push_back('1' + processed + '0');
                start = i + 1;
            }
        }

        // sort karo descending order me reverse karke
        sort(substring.rbegin(),substring.rend());
        string result;
        for(string &str : substring) {
            result += str;
        }
        return result;
    }
};