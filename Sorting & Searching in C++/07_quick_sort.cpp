// Time Complexity - O(nlogn)
// Worst Time Complexity - O(n^2)
// Space Complexity - O(1)

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
    int index = start - 1, pivot = arr[end];
    for(int j = start; j < end; j++) {
        if(arr[j] <= pivot) {
            index++;
            swap(arr[j],arr[index]);
        }
    }
    index++;
    swap(arr[end],arr[index]);
    return index;
}

void quickSort(vector<int> &arr, int start, int end) {
    if(start < end) {
        int pivotIndex = partition(arr,start,end);
        quickSort(arr,start,pivotIndex - 1); // left half
        quickSort(arr,pivotIndex + 1,end); // right half
    }
}

int main() {
    vector<int> arr = {5,2,6,4,1,3};
    cout << "Original Array: ";
    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    
    quickSort(arr,0,arr.size() - 1);
    cout << "Sorted Array using quick sort: ";
    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}