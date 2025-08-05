// Problem - Aggressive Cows - GeeksforGeeks

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int n, int c, int maxAllowedDistance) {
    int cows = 1, lastStallPosition = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] - lastStallPosition >= maxAllowedDistance) {
            cows++;
            lastStallPosition = arr[i];
        }
        if(cows == c) {
            return true; // enough cows can be placed
        }
    }
    return false; // not enough cows can be placed
}

int getDistance(vector<int> &arr, int n, int c) {
    sort(arr.begin(), arr.end());
    int start = 0, end = arr[n-1] - arr[0]; // range of possible answers
    int ans = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(isPossible(arr,n,c,mid)) { // right
            ans = mid;
            start = mid + 1; // try for a larger distance
        }
        else { // left
            end = mid - 1; // try for a smaller distance
        }
    }
    return ans; // maximum minimum distance
}

int main() {
    vector<int> arr = {1,2,8,4,9};
    int n = 5, c = 3;
    cout << "Maximum minimum distance: " << getDistance(arr, n, c) << endl;
    return 0;
}