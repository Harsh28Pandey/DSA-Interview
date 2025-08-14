// Problem - Ways to express an Integer as Sum of Powers

const int MOD = 1e9 + 7;
int numberOfWays(int n, int x) {
    vector<int> powers;
    for (int i = 1; pow(i, x) <= n; i++) {
        powers.push_back((int)pow(i, x));
    }
    int m = powers.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    function<int(int, int)> solve = [&](int rem, int idx) -> int {
        if (rem == 0) return 1;
        if (rem < 0 || idx >= m) return 0;
        if (dp[rem][idx] != -1) return dp[rem][idx];

        long long take = solve(rem - powers[idx], idx + 1);
        long long skip = solve(rem, idx + 1);
        return dp[rem][idx] = (take + skip) % MOD;
    };
    return solve(n, 0);
}