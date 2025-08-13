// Problem - Range Product Queries of Powers (2438) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    // Step 1: Extract powers from n
    vector<long long> powers;
    for (int i = 0; i < 31; i++) {
        if (n & (1 << i)) {
            powers.push_back((1LL << i) % MOD);
        }
    }

    // Step 2: Precompute prefix products
    vector<long long> prefix(powers.size());
    prefix[0] = powers[0];
    for (int i = 1; i < powers.size(); i++) {
        prefix[i] = (prefix[i-1] * powers[i]) % MOD;
    }

    // Step 3: Answer queries
    vector<int> ans;
    ans.reserve(queries.size());

    for (auto &q : queries) {
        int l = q[0], r = q[1];
        long long res;
        if (l == 0) {
            res = prefix[r];
        } else {
            long long numerator = prefix[r];
            long long denominator = prefix[l - 1];
            long long invDenominator = modPow(denominator, MOD - 2);
            res = (numerator * invDenominator) % MOD;
        }
        ans.push_back((int)res);
    }

    return ans;
}