// Problem - Search a 2D Matrix (74) - LeetCode

#include<iostream>
#include<vector>
using namespace std;

bool searchInRow(vector<vector<int>> &matrix, int target, int row) {
    int n = matrix[0].size();
    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(matrix[row][mid] == target) {
            return true;
        }
        else if(matrix[row][mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int startRow = 0, endRow = m - 1;
    while(startRow <= endRow) {
        int midrow = startRow + (endRow - startRow) / 2;
        if(target >= matrix[midrow][0] && target <= matrix[midrow][n - 1]) {
            return searchInRow(matrix,target, midrow);
        }
        else if(target >= matrix[midrow][n - 1]) {
            startRow = midrow + 1;
        }
        else {
            endRow = midrow - 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
        {61, 66, 70, 80}
    };
    int target = 3;
    bool found = searchMatrix(matrix, target);
    
    if(found) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }
    
    return 0;
}