// Time Complexity - O(n)

#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i; // Return the index of the target element
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;

    cout << "Array: ";
    printArray(arr, n);

    int result = linearSearch(arr, n, target);
    if(result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } 
    else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}