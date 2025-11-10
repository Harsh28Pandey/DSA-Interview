// Problem - Zero Sum Subarray - gfg
// Time Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubarray(vector<int> &arr) {
        int n = arr.size();
        int total = 0; // total number of subarrays whose sum is zero
        unordered_map<int,int> m;
        m[0] = 1; // prefix sum 0 appears once initially
        int prefixSum = 0;
        
        for(int i = 0; i < n; i++) {
            prefixSum += arr[i];
            if(m.count(prefixSum)) {
                total += m[prefixSum];
                m[prefixSum]++;
            } else {
                m[prefixSum] = 1;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;

    // ----- Example 1: Hardcoded input -----
    vector<int> arr = {0, 0, 5, 5, 0, 0};

    int result = sol.findSubarray(arr);
    cout << "Total number of subarrays with sum 0: " << result << endl;

    // ----- Example 2: User input version -----
    /*
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int result = sol.findSubarray(arr);
    cout << "Total number of subarrays with sum 0: " << result << endl;
    */

    return 0;
}