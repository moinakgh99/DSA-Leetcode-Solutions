class Solution {
public:

    // Gives TLE ...

    /*
    int M = 1e9+7;
    int dp[1001][1001];

    int solve(int n, int k, int i) {
        if (k == 0) 
            return 1;

        if (i >= n)
            return 0;

        if(dp[k][i] != -1) {
            return dp[k][i];
        }

        long long take = 0; 
        for(int j = i+1; j <= n-1; j++) {
            take = (take + solve(n, k-1, j)) % M;
        }

        long long skip = solve(n, k, i+1) % M;

        return dp[k][i] = take + skip;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, 0) % M;
    }
    */

    // Combinatorial solution
    
    const long long MOD = 1e9 + 7;

    long long modPower(long long base, long long exponent) {

        long long result = 1;

        while (exponent > 0) {

            if (exponent % 2 == 1) {
                result = result * base % MOD;
            }

            base = base * base % MOD;
            exponent /= 2;
        }

        return result;
    }

    int numberOfSets(int n, int k) {

        int N = n + k - 1;
        int R = 2 * k;

        // Calculate N!
        long long factN = 1;

        for (int i = 1; i <= N; i++) {
            factN = factN * i % MOD;
        }

        // Calculate R!
        long long factR = 1;

        for (int i = 1; i <= R; i++) {
            factR = factR * i % MOD;
        }

        // Calculate (N-R)!
        long long factNR = 1;

        for (int i = 1; i <= N - R; i++) {
            factNR = factNR * i % MOD;
        }

        // C(N, R) = N! / (R! * (N-R)!)
        long long denominator = factR * factNR % MOD;

        long long inverse =
            modPower(denominator, MOD - 2);

        return factN * inverse % MOD;
    }
};