// Problem - Number of Zero-Filled Subarrays (2348) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

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

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers (0 or non-zero): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long result = zeroFilledSubarray(nums);
    cout << "Total zero-filled subarrays: " << result << endl;

    return 0;
}