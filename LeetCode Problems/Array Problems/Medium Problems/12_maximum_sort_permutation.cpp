// Problem - Maximum K to Sort Permutations (3644) - LeetCode

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int sortPermutation(vector<int>& nums) {
    int n = nums.size();
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    int ans = -1; // sentinel meaning "no mismatch seen yet"

    for (int i = 0; i < n; ++i) {
        if (nums[i] != sorted[i]) {
            if (ans == -1) ans = nums[i];
            else ans &= nums[i];
        }
    }
    return ans == -1 ? 0 : ans;
}

int main() {
    vector<int> nums = {3, 1, 2, 4}; // You can modify this for other test cases

    int result = sortPermutation(nums);
    cout << "Maximum K to sort permutation: " << result << endl;

    return 0;
}