// Problem - Frequency of the Most Frequent Element (1838) - LeetCode
// Time Complexity - O(n logn)
// Space Complexity - O(n)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maximum = 0;
        long sum = 0;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 0;

        while(j < nums.size()) {
            sum += nums[j];

            while((long)nums[j] * (j - i + 1) - sum > k) {
                sum -= nums[i];
                i++;
            }

            maximum = max(maximum,j - i + 1);
            j++;
        }
        return maximum;
    }
};