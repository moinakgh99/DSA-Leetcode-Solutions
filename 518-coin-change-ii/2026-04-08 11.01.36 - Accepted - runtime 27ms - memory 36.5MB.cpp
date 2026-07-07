class Solution {
public:
    int f(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp) {

        if(amount < 0) return 0;
        if(idx == 0) return amount % coins[idx] == 0;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int notPick = f(idx-1, amount, coins, dp);
        int pick = 0;

        if(amount >= coins[idx]) {
            pick = f(idx, amount - coins[idx], coins, dp);
        }

        return dp[idx][amount] = pick + notPick;
    }


    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        return f(n-1, amount, coins, dp);
    }
};