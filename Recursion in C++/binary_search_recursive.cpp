#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target) {
    if(start > end) {
        return -1; // Base case: target not found
    }
    
    int mid = start + (end - start) / 2; // To avoid overflow
    if(arr[mid] == target) {
        return mid; // Return the index of the target element
    }
    else if(arr[mid] < target) {
        return binarySearch(arr, mid + 1, end, target); // Search in the right half
    }
    else {
        return binarySearch(arr, start, mid - 1, target); // Search in the left half
    }
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
    int target = 64;

    cout << "Array: ";
    printArray(arr, n);

    int result = binarySearch(arr, 0, n - 1, target);
    if(result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } 
    else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}