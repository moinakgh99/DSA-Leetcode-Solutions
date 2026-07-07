class Solution {
public:

    vector<vector<int>> direction{{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    bool check(vector<vector<int>> &distNearestThief, int sf) {
        int n = distNearestThief.size();

        if(distNearestThief[0][0] < sf || distNearestThief[n-1][n-1] < sf) return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()) {
            int curr_i = q.front().first;
            int curr_j = q.front().second;

            q.pop();

            if(curr_i == n - 1 && curr_j == n - 1) return true;

            for(vector<int> &dir : direction) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j]) continue;

                if(distNearestThief[new_i][new_j] < sf) continue;   // reject this cell ..
                
                q.push({new_i, new_j});
                visited[new_i][new_j] = true;
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1 : PreCalculations of distNearestThief -> for each cell
        vector<vector<int>> distNearestThief(n, vector<int> (n, -1));
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // push all cells in queue where thieves are present
        // jha jha p theives present h , vo sbse pehle queue me daaldo
        // unka manhatan distance 0 krdo
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();
                distNearestThief[curr_i][curr_j] = level;
                
                // ab unka neighbors k paas jaao ... 
                for(vector<int> &dir : direction) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j]) {
                        continue;
                    }
                    q.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
            level++;
        }

        // Step 2 : Apply Bnary Search in SF
        int l = 0, r = 2 * n, res = 0;
        while(l <= r) {
            int mid_sf = l + (r - l) / 2;
            if(check(distNearestThief, mid_sf)) {    // >= mid_sf hona chaiya
                res = mid_sf;
                l = mid_sf + 1;   // Thoda greedy ho rh hu, aaga aur check krunga
            }
            else r = mid_sf - 1;
        }

        return res;
    }
};