// Problem - Two Sum II - Input Array is Sorted
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j  = numbers.size() - 1;
        vector<int> ans;

        while(i < j) {
            int sum = numbers[i] + numbers[j];

            if(sum > target) {
                j = j - 1;
            }
            else if(sum < target) {
                i = i + 1;
            }
            else {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
        }
        return ans;
    }
};