class Solution {
public:

    vector<vector<int>> direction{{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // result[i][j] = min health from [0][0] to [i][j]...
        vector<vector<int,int>> res(m, vector<int>(n, INT_MAX));

        dequeue<pair<int,int>> dq;

        result[0][0] = grid[0][0];  // source hmara [0][0] h !!

        dq.push_front({0,0});

        while(!dq.empty()) {
            auto[r,c] = dq.front();
            dq.pop_front();

            for(auto &dir : direction) {
                int nr = r + dir[0];
                int nc = r + dir[1];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                if(res[r][c] + grid[nr][nc] < res[nr][nc]) {
                    res[nr][nc] = res[r][c] + grid[nr][nc];
                }

                if(grid[nr][nc] == 0) dq.push_front({nr, nc});
                else dq.push_back({nr, nc});
            }
        }

        int x = res[m-1][n-1];
        return res- x >= 1;
    }
};