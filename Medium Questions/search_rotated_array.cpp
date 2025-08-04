// Problem - Search in Rotated Sorted Array (33) - Leetcode

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[start] <= nums[mid]) { // left sorted
            if(nums[start] <= target && target <= nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        else { // right sorted
            if(nums[mid] <= target && target <= nums[end]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = search(nums, target);
    cout << "The index of the target " << target << " is: " << result << endl;
    return 0;
}