// Problem - Painter's Partition Problem - HackerEarth

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime) {
    int painters = 1, time = 0;
    for(int i = 0; i < n; i++) {
        if(time + arr[i] <= maxAllowedTime) {
            time += arr[i];
        }
        else {
            painters++;
            time = arr[i];
        }
    }
    return painters <= m;
}

int minTimeToPaint(vector<int> &arr, int n, int m) {
    int sum = 0, maxVal = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    int start = maxVal, end = sum; // range of possible answers
    int ans = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(isPossible(arr, n, m, mid)) { // left
            ans = mid;
            end = mid - 1;
        }
        else { // right
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {40,30,20,10};
    int n = 4, m = 2;
    cout << "Minimum time to paint: " << minTimeToPaint(arr, n, m) << endl;
    return 0;
}