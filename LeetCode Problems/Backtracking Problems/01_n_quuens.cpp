// Problem - N-Queens (51) - LeetCode
// Time Complexity: O(N!)

class Solution {
public:
    bool check(int n, vector<string> &board, int i, int j) {
        // upper left diagonal, koi bhi queen present 
        int row = i, col = j;
        while(row > -1 && col > -1) {
            if(board[row][col] == 'Q')
            return 0;

            row--;
            col--;
        }

        // upper right diagonal
        row = i, col = j;
        while(row > -1 && col < n) {
            if(board[row][col] == 'Q')
            return 0;

            row--;
            col++;
        }
        return 1;
    }

    void find(int row, int n, vector<vector<string>> &ans, vector<string> &board, vector<bool> &column) {
        if(row == n) {
            ans.push_back(board);
            return ;
        }

        // put queen at any n position
        for(int j = 0; j < n; j++) {
            if(column[j] == 0 && check(n,board,row,j)) {
                column[j] = 1;
                board[row][j] = 'Q';
                find(row + 1, n, ans, board,column);
                column[j] = 0;
                board[row][j] = '.';
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

        vector<bool> column(n,0);
        find(0,n,ans,board,column);
        return ans;
    }
};