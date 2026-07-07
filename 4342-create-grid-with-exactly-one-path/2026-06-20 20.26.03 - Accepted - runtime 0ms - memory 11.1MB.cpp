class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grids(m, string(n, '#'));

        for(int j = 0; j < n; j++) {
            grids[0][j] = '.';
        }

        for(int i = 0; i < m; i++) {
            grids[i][n-1] = '.';
        }

        return grids;
    }
};