// Problem - Check Knight Tour Configuration (2596) - LeetCode
// Time Complexity - O(8^n^2)
// Space Complexity - O(n^2)

#include<iostream>
#include<vector>
#include <utility>
#include <cmath>
using namespace std;

bool checkValidGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    
    // Step 1: Create a map from move number to coordinates
    vector<pair<int, int>> pos(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pos[grid[i][j]] = {i, j};
        }
    }

    // Step 2: Check starting point is (0, 0)
    if (pos[0] != make_pair(0, 0)) return false;

    // Step 3: Check each consecutive move is valid
    for (int i = 1; i < n * n; ++i) {
        int dx = abs(pos[i].first - pos[i - 1].first);
        int dy = abs(pos[i].second - pos[i - 1].second);

        // Check for valid knight move
        if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1))) {
            return false;
        }
    }

    return true;
}

int main() {
    // Example input
    vector<vector<int>> grid = {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22}
    };

    // Call the function and output the result
    if (checkValidGrid(grid)) {
        cout << "True (Valid Knight Tour)" << endl;
    } else {
        cout << "False (Invalid Knight Tour)" << endl;
    }

    return 0;
}