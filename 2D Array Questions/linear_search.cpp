#include<iostream>
using namespace std;

bool linearSearch(int matrix[][3], int rows, int cols, int target) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == target) {
                return true; // Target found
            }
        }
    }
    return false; // Target not found
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int target = 5;

    if(linearSearch(matrix, 3, 3, target)) {
        cout << "Target found!" << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}