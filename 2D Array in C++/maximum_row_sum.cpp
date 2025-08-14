#include<iostream>
#include<climits>
using namespace std;

int maximumRowSum(int matrix[][3], int rows, int cols) {
    int maxSum = INT_MIN;
    for(int i = 0; i < rows; i++) {
        int rowSum = 0;
        for(int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        maxSum = max(maxSum, rowSum);
    }
    return maxSum;
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int maxRowSum = maximumRowSum(matrix, 3, 3);
    cout << "Maximum row sum is: " << maxRowSum << endl;

    return 0;
}