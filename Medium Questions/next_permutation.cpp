// Problem - Next Permutation (31) - Leetcode

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int> &nums) {
    // find tthe pivot element
    int n = nums.size();
    int pivot = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }
    if(pivot == -1) {
        reverse(nums.begin(), nums.end()); // in-place changes
        return;
    }

    // next larger element
    for(int i = n - 1; i > pivot; i--) {
        if(nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // reverse (pivot + 1 to n - 1)
    int i = pivot + 1, j = n - 1;
    while(i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}