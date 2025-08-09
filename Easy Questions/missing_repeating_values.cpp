// Problem - Find Missing and Repeating Values (2965) - LeetCode

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> fingMissing(vector<vector<int>> &grid) {
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a,b;
    int expectedSum = 0, actualSum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            actualSum += grid[i][j];
            if(s.find(grid[i][j]) != s.end()) {
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expectedSum = (n * n) * (n * n + 1) / 2;
    b = expectedSum + a - actualSum;
    ans.push_back(b);
    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 8}
    };
    
    vector<int> result = fingMissing(grid);
    cout << "Repeating value: " << result[0] << ",\n Missing value: " << result[1] << endl;
    return 0;
}