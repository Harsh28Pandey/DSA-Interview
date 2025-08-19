// Problem - Number of Zero-Filled Subarrays (2348) - LeetCode

long long zeroFilledSubarray(vector<int>& nums) {
    long long count = 0;   // final result
    long long streak = 0;  // current streak of consecutive zeros

    for (int num : nums) {
        if (num == 0) {
            streak++;         // extend the zero streak
            count += streak;  // add subarrays ending here
        } else {
            streak = 0;       // reset when non-zero found
        }
    }
    return count;
}