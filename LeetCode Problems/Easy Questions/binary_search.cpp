// Problem - Binary Search (704) - LeetCode
// Time Complexity: O(log n)
// Space Complexity: O(log n)

#include <iostream>
#include <vector>
using namespace std;

// Recursive binary search function
int binarySearch(vector<int> &nums, int target, int start, int end) {
    if (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, end);
        } else {
            return binarySearch(nums, target, start, mid - 1);
        }
    }
    return -1; // Target not found
}

// Wrapper function to start binary search
int search(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;
    return binarySearch(nums, target, start, end);
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = search(nums, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }
    return 0;
}