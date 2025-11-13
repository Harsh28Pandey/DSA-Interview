// Problem - Two Sum (1) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int lookingFor = target - nums[i];

            if(m.find(lookingFor) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[lookingFor]);
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};