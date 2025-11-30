// Problem - 3 Sum (15) - LeetCode
// Time Complexity - O(n log n + n * n)
// Space Complexity - O(log n)

class Solution {
public:
     void twoSumHelper(int start, int target, vector<int>& nums, vector<vector<int>>& ans) {
        int i = start;
        int j = nums.size() - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum < target) {
                i++;
            } 
            else if (sum > target) {
                j--;
            } 
            else {
                // ✅ Found a pair that works with nums[start-1]
                ans.push_back({-target, nums[i], nums[j]});
                
                i++;
                j--;
                // Skip duplicate values for nums[i] and nums[j]
                while (i < j && nums[i] == nums[i - 1]) i++;
                while (i < j && nums[j] == nums[j + 1]) j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size(); k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;  // skip duplicates

            int target = -nums[k];
            twoSumHelper(k + 1, target, nums, ans);
        }
        return ans;
    }
};