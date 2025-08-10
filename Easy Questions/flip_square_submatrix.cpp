// Problem - Flip Square Submatrix Vertically (3643) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
        int topRow = x + i;
        int bottomRow = x + k - 1 - i;
        for (int col = 0; col < k; col++) {
            swap(grid[topRow][y + col], grid[bottomRow][y + col]);
        }
    }
    return grid;
}

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    
    // Input the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Reverse the submatrix
    grid = reverseSubmatrix(grid, x, y, k);
    
    // Output the modified grid
    for (const auto& row : grid) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}