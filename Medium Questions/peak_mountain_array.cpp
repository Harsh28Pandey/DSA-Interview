// Problem - Peak Index in a Mountain Array (852) - Leetcode

#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr) {
    int start = 1, end = arr.size() - 2;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        else if(arr[mid - 1] < arr[mid]) { // right
            start = mid + 1;
        }
        else { // left
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {0,3,8,9,5,2};
    int result = peakIndexInMountainArray(arr);
    cout << "The peak index in the mountain array is: " << result << endl;
    return 0;
}