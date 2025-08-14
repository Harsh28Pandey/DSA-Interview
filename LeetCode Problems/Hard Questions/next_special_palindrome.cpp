// Problem - Next Special Palindrome Number (3646) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

vector<long long> specials;

void generateSpecials() {
    if (!specials.empty()) return;
    const long long MAX_LL = LLONG_MAX;

    // We iterate subsets of digits 1..9 (mask bit i -> digit i+1)
    for (int mask = 1; mask < (1 << 9); ++mask) {
        int oddCount = 0;
        int oddDigit = -1;
        int leftCounts[10] = {0};
        int leftLen = 0;
        int palLen = 0;

        for (int i = 0; i < 9; ++i) {
            if (mask & (1 << i)) {
                int d = i + 1;
                palLen += d;
                if (d % 2 == 1) {
                    ++oddCount;
                    oddDigit = d;
                }
                leftCounts[d] = d / 2;       // how many of digit d go to the left half
                leftLen += leftCounts[d];
            }
        }

        // Palindrome is impossible if more than one digit has odd occurrences.
        if (oddCount > 1) continue;

        // If palindrome length can't fit in long long, skip (avoid overflow/exceptions).
        if (palLen > 19) continue;

        // Build left half string (sorted).
        string left;
        left.reserve(leftLen);
        for (int d = 1; d <= 9; ++d) {
            if (leftCounts[d] > 0) left.append(leftCounts[d], char('0' + d));
        }
        sort(left.begin(), left.end());

        // Enumerate unique permutations of left half only.
        // left contains digits from 1..9 only (no zeros), so no leading-zero issue.
        do {
            // build numeric value safely with __int128
            __int128 val = 0;
            for (char c : left) {
                val = val * 10 + (c - '0');
                if (val > MAX_LL) break;
            }

            if (oddDigit != -1) {
                val = val * 10 + oddDigit;
                if (val > MAX_LL) continue;
            }

            for (int i = (int)left.size() - 1; i >= 0; --i) {
                val = val * 10 + (left[i] - '0');
                if (val > MAX_LL) break;
            }

            if (val <= MAX_LL) specials.push_back((long long)val);
        } while (next_permutation(left.begin(), left.end()));
    }

    sort(specials.begin(), specials.end());
    specials.erase(unique(specials.begin(), specials.end()), specials.end());
}

    long long specialPalindrome(long long n) {
    if (specials.empty()) generateSpecials();
    auto it = upper_bound(specials.begin(), specials.end(), n);
    return (it != specials.end()) ? *it : -1; // return -1 if none <= LLONG_MAX is > n
}