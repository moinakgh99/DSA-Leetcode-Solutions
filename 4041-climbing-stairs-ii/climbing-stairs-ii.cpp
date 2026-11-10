class Solution {
public:

    // Approach 1 : gives TLE ....
    /*
    int solve(int i, int n, vector<int>& costs) {
        if(i == n) return 0;

        int cost = INT_MAX;

        int j = i + 1;
        if(j <= n) cost = (costs[j-1] + (j - i) * (j - i)) + solve(j, n, costs);

        j = i + 2;
        if(j <= n) cost = min(cost, (costs[j-1] + (j - i) * (j - i)) + solve(j, n, costs));

        j = i + 3;
        if(j <= n) cost = min(cost, (costs[j-1] + (j - i) * (j - i)) + solve(j, n, costs));

        return cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        return solve(0, n, costs);
    }
    */


    // Approach 2 : Bottom Up Approach ...
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--) {
            int cost = INT_MAX;

            int j = i + 1;
            if(j <= n) cost = (costs[j-1] + (j - i) * (j - i)) + dp[j];

            j = i + 2;
            if(j <= n) cost = min(cost, (costs[j-1] + (j - i) * (j - i)) + dp[j]);

            j = i + 3;
            if(j <= n) cost = min(cost, (costs[j-1] + (j - i) * (j - i)) + dp[j]);

            dp[i] = cost;
        }

        return dp[0];
    }
};