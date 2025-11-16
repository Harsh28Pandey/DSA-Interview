// Problem - Sort Colors (75) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int k = 0;

        while(k <= j) {
            if(nums[k] == 1) {
                k = k + 1;
            }
            else if(nums[k] == 2) {
                swap(nums[j],nums[k]);
                j = j - 1;
            }
            else {
                swap(nums[i],nums[k]);
                i = i + 1;
                k = k + 1;
            }
        }
    }
};