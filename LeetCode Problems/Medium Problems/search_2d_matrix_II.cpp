// Problem - Search a 2D Matrix II (240) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;
    while(row < m && col >= 0) {
        if(target == matrix[row][col]) {
            return true;
        }
        else if(target < matrix[row][col]) {
            col--;
        }
        else {
            row++;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 5;
    bool found = searchMatrix(matrix, target);
    
    if(found) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }
    
    return 0;
}