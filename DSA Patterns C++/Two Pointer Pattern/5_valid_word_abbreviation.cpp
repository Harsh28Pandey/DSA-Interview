// Problem - Valid Word Abbreviation - NeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;

        while(i < word.size() && j < abbr.size()) {
            char abbrCharacter = abbr[j];
            char wordCharacter = word[i];

            if(isdigit(abbrCharacter)) {
                if(abbrCharacter == '0') {
                    return false;
                }

                int curr = 0;
                while(j < abbrCharacter && isdigit(abbr[j])) {
                    curr = curr * 10 + (abbr[j] - '0');
                    j = j + 1;
                }

                i = i + curr;
            }
            else {
                if(wordCharacter != abbrCharacter) {
                    return false;
                }

                i = i + 1;
                j = j + 1;
            }
        }
        return i == word.size() && j == abbr.size();
    }
};