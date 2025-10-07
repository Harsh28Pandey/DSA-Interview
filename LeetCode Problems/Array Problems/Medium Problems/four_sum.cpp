// Problem - four Sum (18) - LeetCode
// Time Complexity: O(n^3 + nlogn)
// Space Complexity: O(uniqueGroups)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for(int j = i + 1; j < n; j++) {
            int p = j + 1, q = n - 1;
            while(p < q) {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
                if(sum < target) {
                    p++;
                }
                else if(sum > target) {
                    q--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;
                    while(p < q && nums[p] == nums[p - 1]) {
                        p++; // Skip duplicates for p
                    }
                }
            }
            j++;
            while(j < n && nums[j] == nums[j - 1]) {
                j++; // Skip duplicates for j
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2}; // Example input
    int target = 0; // Example target
    vector<vector<int>> result = fourSum(nums, target);
    cout << "Four Sum Quadruplets:" << endl;
    for(const auto &quadruplet : result) {
        cout << "[" << quadruplet[0] << ", " << quadruplet[1] << ", " << quadruplet[2] << ", " << quadruplet[3] << "]" << endl;
    }
    return 0;
}