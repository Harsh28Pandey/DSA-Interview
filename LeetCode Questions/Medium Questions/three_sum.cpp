// Problem - Three Sum (15) - LeetCode
// Time Complexity: O(nlogn + n^n)
// Space Compexity: O(uniqueTriplets)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end()); // Sort the array
    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int j = i + 1, k = n - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            }
            else if(sum > 0) {
                k--;
            }
            else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k++;
                while(j < k && nums[j] == nums[j - 1]) {
                    j++; // Skip duplicates for j
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Example input
    vector<vector<int>> result = threeSum(nums);
    cout << "Three Sum Triplets:" << endl;
    for(const auto &triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    return 0;
}