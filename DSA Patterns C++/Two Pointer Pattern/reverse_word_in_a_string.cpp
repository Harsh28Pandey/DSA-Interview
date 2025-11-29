// Problem - Reverse Words in a String (151) - LeetCode

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Trim and split words manually
        vector<string> arr;
        string temp = "";
        
        // Remove extra spaces and split
        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    arr.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) arr.push_back(temp);

        // Step 2: Reverse the words
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

        // Step 3: Join back into a string
        string result = "";
        for (int k = 0; k < arr.size(); k++) {
            result += arr[k];
            if (k != arr.size() - 1) result += " ";
        }
        return result;
    }
};
