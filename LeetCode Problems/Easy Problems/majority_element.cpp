// Problem - Majority Element (169) - Leetcode

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int freq = 0, ans = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(freq == 0) {
            ans = nums[i];
        }
        if(ans == nums[i]) {
            freq++;
        }
        else {
            freq--;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 2, 3, 2, 8 , 9, 8 , 6 , 6 , 6, 8};
    int result = majorityElement(nums);
    cout << "The majority element is: " << result << endl;
    return 0;
}