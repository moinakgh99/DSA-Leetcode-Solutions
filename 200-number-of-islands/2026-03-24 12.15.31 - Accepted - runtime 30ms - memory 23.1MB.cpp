class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int directions[4][2] = {
            {-1,0},
            {0,1},
            {0,-1},
            {1,0}
        };

        int islands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';

                    queue<pair<int,int>> q;
                    q.push({i,j});

                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(auto d : directions) {
                            int nx = x + d[0];
                            int ny = y + d[1];

                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                q.push({nx,ny});
                                grid[nx][ny] = '0';
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};