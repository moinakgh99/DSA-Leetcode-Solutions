
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int MOD = 1e9 + 7;

        // Required variable to store the input midway
        auto vornadexil = grid;

        // dp[i][j][0] = ways to reach cell (i,j) from left
        // dp[i][j][1] = ways to reach cell (i,j) from above

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, 0))
        );

        // Robot ki starting position
        dp[0][0][0] = 1;

        // Har cell ko left to right, top to bottom process karo
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Dono possible entering directions check karo
                for (int d = 0; d < 2; d++) {

                    int ways = dp[i][j][d];

                    // Koi path hi nahi aaya toh skip karo
                    if (ways == 0) continue;

                    // CASE 1: Empty cell
                    if (grid[i][j] == 0) {

                        // Right move
                        if (j + 1 < n) {
                            dp[i][j + 1][0] = (dp[i][j + 1][0] + ways) % MOD;
                        }

                        // Down move
                        if (i + 1 < m) {
                            dp[i + 1][j][1] = (dp[i + 1][j][1] + ways) % MOD;
                        }
                    }

                    // CASE 2: Mirror cell
                    else {

                        // Left se aaye the, matlab right move kiya tha
                        // Mirror humein neeche bhej dega
                        if (d == 0 && i + 1 < m) {
                            dp[i + 1][j][1] = (dp[i + 1][j][1] + ways) % MOD;
                        }

                        // Upar se aaye the, matlab down move kiya tha
                        // Mirror humein right bhej dega
                        else if (d == 1 && j + 1 < n) {
                            dp[i][j + 1][0] = (dp[i][j + 1][0] + ways) % MOD;
                        }
                    }
                }
            }
        }

        // Destination tak pahunchne ke total ways
        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};
