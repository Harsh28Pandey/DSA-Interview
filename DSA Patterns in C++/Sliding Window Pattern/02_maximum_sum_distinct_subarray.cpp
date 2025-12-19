// Problem - Maximum Sum of Distinct Subarrays with Length K (2461) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, ans = 0;
        unordered_map<int,int> freq;
        int n = nums.size();

        int l = 0;

        for (int r = 0; r < n; r++) {
            // expand right
            freq[nums[r]]++;
            sum += nums[r];

            // keep window size <= k
            if (r - l + 1 > k) {
                freq[nums[l]]--;
                sum -= nums[l];
                if (freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }

            // when window size == k, check distinct count
            if (r - l + 1 == k && freq.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
