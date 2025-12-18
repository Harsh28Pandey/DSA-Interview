// Problem - Single Element in a Sorted Array (540) - Leetcode

#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) 
    return nums[0];

    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(mid == 0 && nums[0] != nums[1])
        return nums[mid];

        if(mid == n - 1 && nums[n - 1] != nums[n - 2])
        return nums[mid];

        if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) 
        return nums[mid];

        if(mid % 2 == 0) { // even
            if(nums[mid - 1] == nums[mid]) { // left
                end = mid - 1;
            }
            else { // right
                start = mid + 1;
            }
        }
        else { // odd
            if(nums[mid - 1] == nums[mid]) { // right
                start = mid + 1;
            }
            else { // left
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int result = singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << result << endl;
    return 0;
}