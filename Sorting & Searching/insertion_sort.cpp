#include<iostream>
using namespace std;

void insertionSortAscending(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void insertionSortDescending(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] < curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
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

    insertionSortAscending(arr, n);
    cout << "Sorted array in Ascending Order: ";
    printArray(arr, n);

    insertionSortDescending(arr, n);
    cout << "Sorted array in Descending Order: ";
    printArray(arr, n);
    
    return 0;
}