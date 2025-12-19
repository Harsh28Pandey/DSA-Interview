// Problem - Find Median in a Stream - gfg

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    priority_queue<int> leftMaxHeap; // max-heap for left half
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; // min-heap for right half
    
    // Function to insert a number into heaps
    void insertHeap(int x) {
        if (leftMaxHeap.empty() || x <= leftMaxHeap.top()) {
            leftMaxHeap.push(x);
        } else {
            rightMinHeap.push(x);
        }
        balanceHeap();
    }

    // Function to balance the sizes of the two heaps
    void balanceHeap() {
        if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } else if (rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
  
    // Function to get current median
    double getMedian() {
        if (leftMaxHeap.size() == rightMinHeap.size()) {
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        } else {
            return leftMaxHeap.top();
        }
    }
};

int main() {
    Solution s;
    vector<int> arr = {5, 15, 1, 3};
    vector<double> medians;

    for (int x : arr) {
        s.insertHeap(x);
        medians.push_back(s.getMedian());
    }

    cout << "Running medians: ";
    for (double m : medians) {
        cout << m << " ";
    }
    cout << endl;

    return 0;
}