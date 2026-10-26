class Solution {
public:

    vector<vector<int>> dir = {{1,0} , {-1,0}, {0,1} , {0,-1}};

    long long dfs(int row, int col, vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        long long sum = grid[row][col];
        grid[row][col] = 0;

        for(vector<int> dirs : dir) {
            int new_row = row + dirs[0];
            int new_col = col + dirs[1];

            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && grid[new_row][new_col] > 0) {
                sum += dfs(new_row, new_col, grid);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int c = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] > 0) {
                    long long sum = dfs(row, col, grid);

                    if(sum % k == 0) c++;
                }
            }
        }

        return c;
    }
};