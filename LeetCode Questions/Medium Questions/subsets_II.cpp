// Problem - Subsets II (90) - LeetCode
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
    int index = i + 1;
    while(index < nums.size() && nums[index] == nums[index - 1]) {
        index++;
    }
    getAllSubsets(nums, ans, index, allSubsets);
}

vector<vector<int>> subsetDuplicates(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsetDuplicates(nums);
    
    for(const auto &subset : result) {
        cout << "{ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}