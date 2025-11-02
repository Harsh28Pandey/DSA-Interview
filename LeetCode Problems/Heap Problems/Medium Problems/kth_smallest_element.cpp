#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> p; // max heap

    for(int i = 0; i < k; i++) {
        p.push(arr[i]);
    }
    for(int i = k; i <= r; i++) {
        if(arr[i] < p.top()) {
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Kth smallest element is: " << kthSmallest(arr, 0, n - 1, k) << endl;
    return 0;
}