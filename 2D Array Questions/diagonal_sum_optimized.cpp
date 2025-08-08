// Time Complexity - O(n)

#include<iostream>
using namespace std;

int diagonalSumOptimized(int matrix[][4], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i]; // Primary diagonal
        if(i != n - i - 1) { // Avoid double counting the center element in odd-sized matrices
            sum += matrix[i][n - i - 1]; // Secondary diagonal
        }
    }
    return sum;
}

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    int n = 4; // Size of the matrix
    int result = diagonalSumOptimized(matrix, n);
    cout << "Diagonal sum is: " << result << endl;

    return 0;
}