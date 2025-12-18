// Problem - Target Sum (494) - Leetcode

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<string, int> memo;
int dfs(vector<int>& nums, int index, int sum, int target) {
    if (index == nums.size()) {
        return sum == target ? 1 : 0;
    }
    
    string key = to_string(index) + "," + to_string(sum);
    if (memo.count(key)) return memo[key];

    int add = dfs(nums, index + 1, sum + nums[index], target);
    int subtract = dfs(nums, index + 1, sum - nums[index], target);

    return memo[key] = add + subtract;
}

int findTargetSumWays(vector<int>& nums, int target) {
    memo.clear();
    return dfs(nums, 0, 0, target);
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}