// Problem - Contains Duplicate II (219) - LeetCode
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;

        for (int i = 0; i < min(k, (int)nums.size()); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }


        for(int i = k; i < nums.size(); i++) {
            if(s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
            s.erase(nums[i - k]);
        }
        return false;
    }
};