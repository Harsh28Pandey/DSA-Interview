// Problem - Count Subarrays With Max Element appears at Least K (2962) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());

        long long total = 0;
        int count = 0;
        int start = 0;

        for(int end = 0; end < n; end++) {
            if(nums[end] == maxElement) {
                count++;
            }

            while(count >= k) {
                total += n - end;
                if(nums[start] == maxElement) {
                    count--;
                }
                start++;
            }
        }
        return total;
    }
};