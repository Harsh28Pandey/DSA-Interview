#include<iostream>
using namespace std;

int binsrySearch(int arr[], int n, int target) {
    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2; // To avoid overflow
        if(arr[mid] == target) {
            return mid; // Return the index of the target element
        }
        else if(arr[mid] < target) {
            start = mid + 1; // Search in the end half
        }
        else {
            end = mid - 1; // Search in the start half
        }
    }
    return -1; // Return -1 if the target element is not found
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 22, 25, 34, 64, 90}; // Array must be sorted for binary search
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;

    cout << "Array: ";
    printArray(arr, n);

    int result = binsrySearch(arr, n, target);
    if(result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } 
    else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}