// Problem - Largest 3-Same-Digit Number in String (2264) - LeetCode

string largestGoodInteger(string num) {
    string ans = "";
for (int i = 0; i <= (int)num.size() - 3; i++) {
    // Extract substring of length 3
    string sub = num.substr(i, 3);

    // Check if all three chars are equal
    if (sub[0] == sub[1] && sub[1] == sub[2]) {
        // Update ans if it's larger
        if (ans.empty() || sub > ans) {
            ans = sub;
        }
    }
}
return ans;
}