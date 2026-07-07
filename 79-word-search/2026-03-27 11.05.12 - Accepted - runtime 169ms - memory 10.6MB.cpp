class Solution {
public:
    bool search(int i, int j, int m, int n, vector<vector<char>>& board, string &word, int idx) {
        if(i < 0 || i == m || j < 0 || j == n || board[i][j] != word[idx]) return false;
        if(idx == word.size() - 1) return true;

        char c = board[i][j];
        board[i][j] = '#';

        bool s1 = search(i+1,j,m,n,board,word,idx+1);
        bool s2 = search(i,j+1,m,n,board,word,idx+1);
        bool s3 = search(i-1,j,m,n,board,word,idx+1);
        bool s4 = search(i,j-1,m,n,board,word,idx+1);

        board[i][j] = c;
        return s1 || s2 || s3 || s4;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(search(i, j, m, n, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
};