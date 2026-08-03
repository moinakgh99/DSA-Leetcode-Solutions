class Solution {
public:

    /*
    // Recursive Approach gives TLE,, need memoization ....
    int solve(int i, vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(i >= n) return 0;

        int res = INT_MIN;

        res = max(res, stoneValue[i] - solve(i + 1, stoneValue));
        if(i + 1 < n) res = max(res, stoneValue[i] + stoneValue[i + 1] - solve(i + 2, stoneValue));
        if(i + 2 < n) res = max(res, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(i + 3, stoneValue));
        
        return res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int diff = solve(0, stoneValue);

        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
    */


    /*
    // Memoization of above code (Top down Approach) ...
    vector<int> dp;
    int solve(int i, vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int res = INT_MIN;

        res = max(res, stoneValue[i] - solve(i + 1, stoneValue));
        if(i + 1 < n) res = max(res, stoneValue[i] + stoneValue[i + 1] - solve(i + 2, stoneValue));
        if(i + 2 < n) res = max(res, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(i + 3, stoneValue));
        
        return dp[i] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n+1, -1);
        int diff = solve(0, stoneValue);

        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
    */


    // Bottom up Approach (Tabulation) ....

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1);

        for(int i = n - 1; i >= 0; i--) {

            dp[i] = stoneValue[i] - dp[i + 1];

            if(i + 2 <= n) dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            if(i + 3 <= n) dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);

        }

        int diff = dp[0];

        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
};