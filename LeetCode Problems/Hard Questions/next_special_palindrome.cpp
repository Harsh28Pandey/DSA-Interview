// Problem - Next Special Palindrome Number (3646) - LeetCode

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>   // For LLONG_MAX
#include <string>
using namespace std;

vector<long long> specials;

// Generate all special palindrome numbers based on the problem constraints.
void generateSpecials() {
    if (!specials.empty()) return;
    const long long MAX_LL = LLONG_MAX;

    // Iterate over all subsets of digits 1..9 (bitmask)
    for (int mask = 1; mask < (1 << 9); ++mask) {
        int oddCount = 0;
        int oddDigit = -1;
        int leftCounts[10] = {0};
        int leftLen = 0;
        int palLen = 0;

        // Calculate counts of digits and palindrome length
        for (int i = 0; i < 9; ++i) {
            if (mask & (1 << i)) {
                int d = i + 1;
                palLen += d;
                if (d % 2 == 1) {
                    ++oddCount;
                    oddDigit = d;
                }
                leftCounts[d] = d / 2;
                leftLen += leftCounts[d];
            }
        }

        // Only one odd-count digit allowed for palindrome
        if (oddCount > 1) continue;

        // Skip if palindrome length exceeds digits that fit in long long
        if (palLen > 19) continue;

        // Build left half string in ascending order
        string left;
        left.reserve(leftLen);
        for (int d = 1; d <= 9; ++d) {
            if (leftCounts[d] > 0) {
                left.append(leftCounts[d], char('0' + d));
            }
        }
        sort(left.begin(), left.end());

        // Generate all unique permutations of left half
        do {
            // Use __int128 for overflow-safe building
            __int128 val = 0;

            // Construct left half value
            for (char c : left) {
                val = val * 10 + (c - '0');
                if (val > MAX_LL) break;
            }
            if (val > MAX_LL) continue;

            // Add odd middle digit if exists
            if (oddDigit != -1) {
                val = val * 10 + oddDigit;
                if (val > MAX_LL) continue;
            }

            // Append reverse of left half
            for (int i = (int)left.size() - 1; i >= 0; --i) {
                val = val * 10 + (left[i] - '0');
                if (val > MAX_LL) break;
            }
            if (val <= MAX_LL) {
                specials.push_back((long long)val);
            }
        } while (next_permutation(left.begin(), left.end()));
    }

    // Remove duplicates and sort
    sort(specials.begin(), specials.end());
    specials.erase(unique(specials.begin(), specials.end()), specials.end());
}

long long specialPalindrome(long long n) {
    if (specials.empty()) generateSpecials();
    auto it = upper_bound(specials.begin(), specials.end(), n);
    return (it != specials.end()) ? *it : -1;
}