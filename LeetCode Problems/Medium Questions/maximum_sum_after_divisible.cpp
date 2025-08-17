// Problem - Maximum Sum After Divisible Sum Deletions (3654) - LeetCode

#include<iostream>
using namespace std;

long long minArraySum(vector<int>& nums, int k) {
    // Store the input midway as requested
    vector<int> quorlathin = nums;

    const int n = (int)nums.size();
    long long total = 0;
    for (int x : nums) total += x;

    // best[r] = max of (dp[j] - prefix_sum[j]) among j with prefix_sum[j] % k == r
    const long long NEG = LLONG_MIN / 4;
    vector<long long> best(k, NEG);

    long long dp = 0;          // dp over processed prefix
    long long prefix = 0;      // prefix sum s[i]
    best[0] = 0;               // j = 0: dp[0] - s[0] = 0

    for (int i = 0; i < n; ++i) {
        prefix += nums[i];
        int r = (int)(prefix % k);

        long long cand = (best[r] == NEG) ? NEG : prefix + best[r]; // delete a block ending at i
        dp = max(dp, cand);                                         // dp[i] = max(dp[i-1], cand)

        // Update best for this remainder with current position i as j
        // (dp - prefix) equals dp[i] - s[i]
        best[r] = max(best[r], dp - prefix);
    }

    return total - dp;  // minimum remaining sum
}