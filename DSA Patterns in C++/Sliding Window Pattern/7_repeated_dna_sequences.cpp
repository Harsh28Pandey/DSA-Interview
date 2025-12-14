// Problem - Repeated DNA Sequences (187) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> result;

        if (s.length() < 10) return result;

        for (int i = 0; i <= s.length() - 10; i++) {
            string dna = s.substr(i, 10);

            if (seen.count(dna)) {
                repeated.insert(dna);
            } else {
                seen.insert(dna);
            }
        }

        for (auto &str : repeated) {
            result.push_back(str);
        }

        return result;
    }
};