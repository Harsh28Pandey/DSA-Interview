// Problem - Rotting Oranges (994) - LeetCode

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q; // ((i, j), time)

        // push all initially rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        // BFS
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            // top
            if(i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) {
                q.push({{i - 1, j}, time + 1});
                visited[i - 1][j] = true;
                grid[i - 1][j] = 2;
            }

            // right
            if(j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, time + 1});
                visited[i][j + 1] = true;
                grid[i][j + 1] = 2;
            }

            // bottom
            if(i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, time + 1});
                visited[i + 1][j] = true;
                grid[i + 1][j] = 2;
            }

            // left
            if(j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, time + 1});
                visited[i][j - 1] = true;
                grid[i][j - 1] = 2;
            }
        }

        // check for remaining fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid elements (0 for empty, 1 for fresh, 2 for rotten):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = sol.orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}