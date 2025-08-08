#include<iostream>
#include<climits>
using namespace std;


int maximumColumnSum(int matrix[][3], int rows, int cols) {
    int maxSum = INT_MIN;
    for(int j = 0; j < cols; j++) {
        int colSum = 0;
        for(int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        maxSum = max(maxSum, colSum);
    }
    return maxSum;

}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int maxColumnSum = maximumColumnSum(matrix, 3, 3);
    cout << "Maximum column sum is: " << maxColumnSum << endl;

    return 0;
}