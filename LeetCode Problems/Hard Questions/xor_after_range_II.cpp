// Problem - XOR After Range Multiplication Queries II (3655) - LeetCode

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int MOD = 1e9 + 7;

long long modpow(long long a, long long e) {
    long long res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();

    // bravexuneth variable to store input midway
    auto bravexuneth = queries;

    int B = sqrt(n) + 1;

    // For small k, difference arrays
    vector<vector<long long>> diff(B, vector<long long>(n + 2, 1));

    for (auto &Q : queries) {
        int l = Q[0], r = Q[1], k = Q[2], v = Q[3];

        if (k >= B) {
            // Large step -> simulate directly
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        } else {
            // Small step -> use difference trick
            diff[k][l] = (1LL * diff[k][l] * v) % MOD;

            int last = l + ((r - l) / k) * k;
            if (last + k < n) {
                long long inv = modpow(v, MOD - 2);
                diff[k][last + k] = (1LL * diff[k][last + k] * inv) % MOD;
            }
        }
    }

    // Apply small-k updates
    for (int k = 1; k < B; k++) {
        vector<long long> cur(k, 1);
        for (int i = 0; i < n; i++) {
            cur[i % k] = (cur[i % k] * diff[k][i]) % MOD;
            nums[i] = (1LL * nums[i] * cur[i % k]) % MOD;
        }
    }

    // Final XOR
    int ans = 0;
    for (int x : nums) ans ^= x;
    return ans;
}

int main() {
    int n, q;
    cout << "Enter the size of nums array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements of nums array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(4));
    cout << "Enter each query in format: l r k v\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    int result = xorAfterQueries(nums, queries);
    cout << "Result after all queries (XOR of array): " << result << "\n";

    return 0;
}