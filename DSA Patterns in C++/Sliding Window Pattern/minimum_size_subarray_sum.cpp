// Problem - Minimum Size Subarray Sum (209) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = INT_MAX;
        int sum = 0;

        int i = 0;
        int j = 0;

        while(j < nums.size()) {
            sum += nums[j];
            while(sum >= target) {
                size = min(size,j - i + 1);
                sum -= nums[i];
                i = i + 1;
            }
            j = j + 1;
        }
        return size == INT_MAX ? 0 : size;
    }
};