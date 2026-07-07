class Solution {
public:

    bool isSafe(vector<string> &board, int r, int c, int n) {

        // Horizontal check
        for(int j = 0; j < n; j++) {
            if(board[r][j] == 'Q') return false;
        }

        // Vertical Check
        for(int i = 0; i < n; i++) {
            if(board[i][c] == 'Q') return false;
        }

        // left Diagonal Check
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }

        // Right Diagonal Check
        for(int i = r, j = c; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }

        return true;

    }


    void nqueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nqueens(board, row + 1, n, ans);
            }
            board[row][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> ans;

        nqueens(board, 0, n, ans);
        return ans;
    }
};