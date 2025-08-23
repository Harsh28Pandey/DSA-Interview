// Problem - Permutations (46) - LeetCode
// Time Complexity - O(n! * n)
// Space Complexity - O(n!)

#include<iostream>
#include<vector>
using namespace std;

void getPermutations(vector<int> &nums, int index, vector<vector<int>> &ans) {
    if(index == nums.size()) {
        ans.push_back({nums});
        return ;
    }
    for(int i = index; i < nums.size(); i++) {
        swap(nums[index],nums[i]);
        getPermutations(nums,index + 1,ans);
        swap(nums[index],nums[i]); // backtracking
    }
}

vector<vector<int>> permutations(vector<int> &nums) {
    vector<vector<int>> ans;
    getPermutations(nums,0,ans);
    return ans;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> result = permutations(arr);
    for(auto &i : result) {
        for(auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}