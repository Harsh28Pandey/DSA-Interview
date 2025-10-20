// Problem - nNumber of Islands (200) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1') {
            return;
        }
        visited[i][j] = true;
        dfs(i - 1, j, visited, grid, n, m);
        dfs(i, j + 1, visited, grid, n, m);
        dfs(i + 1, j, visited, grid, n, m);
        dfs(i, j - 1, visited, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, visited, grid, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    cout << "Enter grid values (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}