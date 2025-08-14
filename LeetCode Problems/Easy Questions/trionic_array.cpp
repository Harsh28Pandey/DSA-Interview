// Problem - Trionic Array I (3637) - LeetCode

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isTrionic(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false;

    int p = 0;
    // Step 1: strictly increasing
    while (p + 1 < n && nums[p] < nums[p + 1]) {
    p++;
    }

    // p cannot be at start or end
    if (p == 0 || p == n - 1) return false;

    int q = p;
    // Step 2: strictly decreasing
    while (q + 1 < n && nums[q] > nums[q + 1]) {
    q++;
    }

    // q cannot be equal to p (no decrease) or at end
    if (q == p || q == n - 1) return false;

    // Step 3: strictly increasing again
    while (q + 1 < n && nums[q] < nums[q + 1]) {
    q++;
    }

    // Must end exactly at last element
    return q == n - 1;
}

int main() {
    vector<int> nums = {1, 3, 2, 4, 5}; // Example input
    if (isTrionic(nums)) {
        cout << "The array is trionic." << endl;
    } else {
        cout << "The array is not trionic." << endl;
    }
    return 0;
}