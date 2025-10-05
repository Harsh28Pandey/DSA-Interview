// Problem - Subsets (78) - LeetCode
// Time Complexity: O(2^n * n)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets) {
    if(i == nums.size()) {
        allSubsets.push_back(ans);
        return ;
    }
    // Include the current element
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);
    // Exclude the current element  
    ans.pop_back();
    getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    
    for(const auto &subset : result) {
        cout << "{ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}