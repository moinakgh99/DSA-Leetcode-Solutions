class Solution {
public:
    int dp[501][501];

    /*
    // memoization of Recursive Approach 1 .... (same as question predict the winner) ....
    int solve(int i, int j, vector<int>& piles) {
        if(i > j) return 0;
        if(i == j) return piles[i];

        if(dp[i][j] != -1) return dp[i][j];

        // alice - bob .... (diff btw them)
        int pick_i = piles[i] - solve(i+1, j, piles);
        int pick_j = piles[j] - solve(i, j-1, piles);

        return dp[i][j] = max(pick_i, pick_j);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, n-1, piles) > 0;
    }
    */


    // Memoization of recursive approach 2 ....

    int solve(int i, int j, vector<int>& piles) {
        if(i > j) return 0;
        if(i == j) return piles[i];

        if(dp[i][j] != -1) return dp[i][j];

        // taking case only for alice
        int pick_i = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles));
        int pick_j = piles[j] + min(solve(i+1, j-1, piles), solve(i, j-2, piles));

        return dp[i][j] = max(pick_i, pick_j);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));

        int total = 0;
        for(int x : piles) total += x;

        int alice = solve(0, n-1, piles);
        int bob = total - alice;

        return alice > bob;
    }
};