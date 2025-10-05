// Problem - Count Square Submatrices with All Ones (1277) - LeetCode

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int result = 0;
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // first row/col
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                result += dp[i][j];
            }
        }
    }
    return result;
}

int main() {
    // Sample input matrix
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    int result = countSquares(matrix);
    cout << "Number of square submatrices with all ones: " << result << endl;

    return 0;
}