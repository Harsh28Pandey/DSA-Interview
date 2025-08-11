// Time Complexity - O(n^2)

#include<iostream>
using namespace std;

void bubbleSortAscending(int arr[],int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j],arr[j + 1]);
            }
        }
    }
}

void bubbleSortDecending(int arr[],int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                swap(arr[j],arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSortAscending(arr, n);
    cout << "Sorted array in Ascending Order: ";
    printArray(arr, n);

    bubbleSortDecending(arr, n);
    cout << "Sorted array in Descending Order: ";
    printArray(arr, n);
    
    return 0;
}