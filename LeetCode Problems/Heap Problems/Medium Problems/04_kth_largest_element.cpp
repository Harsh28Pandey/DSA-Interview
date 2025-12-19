// Problem - Kth Largest Element in an Array (215) - LeetCode

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> p; // min heap

    // Insert first k elements
    for (int i = 0; i < k; i++) {
        p.push(nums[i]);
    }

    // Process remaining elements
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > p.top()) {
            p.pop();
            p.push(nums[i]);
        }
    }

    return p.top();
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "The " << k << "th largest element is: " << findKthLargest(nums, k) << endl;

    return 0;
}