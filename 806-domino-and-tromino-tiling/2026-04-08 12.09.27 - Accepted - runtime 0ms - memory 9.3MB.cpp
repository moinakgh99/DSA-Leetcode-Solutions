class Solution {
public:
    int mod = 1e9+7;
    int numTilings(int n) {
        vector<long long> dp(n+1);
        if(n <= 1) return n;
        if( n == 2 ) return 2;

        dp[0] = 1, dp[1] = 1, dp[2] = 2;

        for(int i = 3; i <= n; i++) {
            dp[i] = (2 * dp[i-1] + dp[i-3]) % mod;
        }

        return dp[n];
    }
};