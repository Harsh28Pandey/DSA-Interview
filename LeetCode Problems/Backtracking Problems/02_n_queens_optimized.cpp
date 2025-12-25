// Problem - N-Queens (51) - LeetCode
// Time Complexity: O(N!)

class Solution {
public:
    void find(int row, int n, vector<vector<string>> &ans, vector<string> &board, vector<bool> &column, vector<bool> &leftDig, vector<bool> &rightDig) {
        if(row == n) {
            ans.push_back(board);
            return ;
        }

        // put queen at any n position
        for(int j = 0; j < n; j++) {
            if(column[j] == 0 && leftDig[n - 1 + j - row] == 0 && rightDig[row + j] == 0) {
                column[j] = 1;
                board[row][j] = 'Q';
                leftDig[n - 1 + j - row] = 1;
                rightDig[row + j] = 1;
                find(row + 1, n, ans, board,column,leftDig, rightDig);
                column[j] = 0;
                board[row][j] = '.';
                leftDig[n - 1 + j - row] = 0;
                rightDig[row + j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i].push_back('.');
            }
        }

        vector<bool> leftDig(2 * n - 1,0);
        vector<bool> rightDig(2 * n - 1,0);
        vector<bool> column(n,0);
        find(0,n,ans,board,column,leftDig,rightDig);
        return ans;
    }
};