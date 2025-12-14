// Problem - Length of Longest Subarray With at most K frequency (2958) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int length = 0;
        unordered_map<int,int> count;
        int start = 0, end = 0, n = nums.size();

        while(end < n) {
            count[nums[end]]++;
            while(count[nums[end]] > k) {
                count[nums[start]]--;
                start++;
            }
            length = max(length,end - start + 1);
            end++;
        }
        return length;
    }
};