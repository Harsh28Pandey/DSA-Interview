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