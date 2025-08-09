// Problem - Find the Duplicate Number (287) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int> &arr) {
    int slow = arr[0], fast = arr[0];
    do {
        slow = arr[slow]; // Move slow by 1 step
        fast = arr[arr[fast]]; // Move fast by 2 steps
    } while (slow != fast);

    slow = arr[0]; // Reset slow to the start
    while(slow != fast) {
        slow = arr[slow]; // Move slow by 1 step
        fast = arr[fast]; // Move fast by 1 step
    }
    return slow; // The duplicate number
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 2}; // Example input
    int duplicate = findDuplicate(arr);
    cout << "The duplicate number is: " << duplicate << endl;
    return 0;
}