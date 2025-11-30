// Problem - Count Pairs Whose Sum is Less Than Target (2824) - LeetCode
// Time Complexity - O(n log n)
// Space Complexity - O(log n)

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int i = 0;
        int j = nums.size() - 1;

        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum < target) {
                count = count + (j - i);
                i = i + 1;
            }
            else {
                j = j - 1;
            }
        }
        return count;
    }
};