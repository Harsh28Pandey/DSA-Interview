// Problem - Minimum Window Substring (76) - LeetCode

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> m;
        for (char c : t) m[c]++;

        int start = 0, end = 0;
        int count = t.size();
        int ans = INT_MAX, index = -1;

        while (end < s.size()) {
            if (m[s[end]] > 0)
                count--;

            m[s[end]]--;

            while (count == 0) {
                if (ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }

                m[s[start]]++;
                if (m[s[start]] > 0)
                    count++;

                start++;
            }
            end++;
        }

        if (index == -1)
            return "";

        return s.substr(index, ans);
    }
};

int main() {
    Solution obj;

    string s, t;
    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    string result = obj.minWindow(s, t);

    if (result == "")
        cout << "No valid window found" << endl;
    else
        cout << "Minimum window substring: " << result << endl;

    return 0;
}
