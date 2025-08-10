// Problem - Find Subarray with Equal Sum (2395) - LeetCode

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool findSubarrays(vector<int>& nums) {
    unordered_set<int> seen;
    for (int i = 0; i < nums.size() - 1; i++) {
    int sum = nums[i] + nums[i + 1];
    if (seen.count(sum)) {
        return true;
    }
    seen.insert(sum);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << boolalpha << findSubarrays(nums) << endl;
    return 0;
}