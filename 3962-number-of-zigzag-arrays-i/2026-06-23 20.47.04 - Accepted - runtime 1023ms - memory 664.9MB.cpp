class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        if(n == 1) return k;
        int mod = 1000000007;
        vector<array<long long,2>> dp(k+1);
        for(int v = 1; v <= k; v++) {
            dp[v][0] = k - v;
            dp[v][1] = v - 1;
        }

        for(int i = 3; i <= n; i++) {
            vector<array<long long,2>> nextDp(k+1);

            long long sum0 = 0;
            for(int v = 1; v <= k; v++) {
                nextDp[v][1] = sum0;
                sum0 = (sum0 + dp[v][0]) % mod;
            }

            long long sum1 = 0;
            for(int v = k; v >= 1; v--) {
                nextDp[v][0] = sum1;
                sum1 = (sum1 + dp[v][1]) % mod;
            }

            dp.swap(nextDp);
        }

        long long total = 0;
        for(int v = 1; v <= k; v++) {
            total = (total + dp[v][0]) % mod;
            total = (total + dp[v][1]) % mod;
        }

        return total;
    }
};