class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        if(n == 1) return k;
        int mod = 1000000007;
        vector<vector<long long>> dp(k+1, vector<long long>(2,0));
        for(int v = 1; v <= k; v++) {
            dp[v][0] = k - v;
            dp[v][1] = v - 1;
        }

        for(int i = 3; i <= n; i++) {
            vector<vector<long long>> dp(k+1, vector<long long>(2,0));

            long sum0 = 0;
            for(int v = 1; v <= k; v++) {
                nextDp[v][1] = (int) sum0;
                sum0 = (sum0 + dp[v][0]) % mod;
            }

            long sum1 = 0;
            for(int v = k; v >= 1; v--) {
                nextDp[v][0] = (int) sum1;
                sum1 = (sum1 + dp[v][1]) % mod;
            }

            dp = nextDp;
        }

        long total = 0;
        for(int v = 1; v <= k; v++) {
            total = (total + dp[v][0]) % mod;
            total = (total + dp[v][1]) % mod;
        }

        return (int) total;
    }
};