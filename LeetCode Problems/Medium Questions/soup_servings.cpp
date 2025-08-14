// Problem - Soup Servings (808) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

unordered_map<int, unordered_map<int, double>> memo;
double dfs(int a, int b) {
    if (a <= 0 && b <= 0) return 0.5;
    if (a <= 0) return 1.0;
    if (b <= 0) return 0.0;
    if (memo[a][b]) return memo[a][b];

    memo[a][b] = 0.25 * (
        dfs(a - 100, b) +
        dfs(a - 75, b - 25) +
        dfs(a - 50, b - 50) +
        dfs(a - 25, b - 75)
    );

    return memo[a][b];
}

double soupServings(int n) {
    // Optimization: For large n, the result approaches 1.0
    if (n >= 5000) return 1.0;
    return dfs(n, n);
}