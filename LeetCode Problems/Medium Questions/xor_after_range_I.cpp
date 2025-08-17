// Problem - XOR After Range Multiplication Queries I (3653) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    const int MOD = 1e9 + 7;

    // midway storage as requested
    auto mortavexil = queries;  

    // Process each query
    for (auto &q : mortavexil) {
        int li = q[0], ri = q[1], ki = q[2], vi = q[3];
        for (int idx = li; idx <= ri; idx += ki) {
            nums[idx] = (1LL * nums[idx] * vi) % MOD;
        }
    }

    // Compute XOR of all elements
    int result = 0;
    for (int x : nums) {
        result ^= x;
    }
    return result;
}

int main() {
    int n, q;
    cout << "Enter the size of nums array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements of nums:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(4));
    cout << "Enter queries in format: li ri ki vi (0-based indices for li and ri)\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    int ans = xorAfterQueries(nums, queries);
    cout << "Result after all queries (XOR of all elements): " << ans << endl;

    return 0;
}