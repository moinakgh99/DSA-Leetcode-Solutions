class Solution {
public:
    int n;

    // Approach 1 : Using Recursion ... gives TLE ...

    /*
    int alice(int left, int right, vector<int> &prefix) {
        if(left >= right) return 0;

        int lSum = 0, rSum = 0;
        int score = 0;

        for(int mid = 0; mid < right; mid++) {
            lSum = prefix[mid] - ((left > 0) ? prefix[left - 1] : 0);  // l .... mid
            rSum = prefix[right] - prefix[mid];  // mid .... right

            if(lSum < rSum) score = max(score, lSum + alice(left, mid, prefix));
            else if(rSum < lSum) score = max(score, rSum + alice(mid+1, right, prefix));
            else score = max({score, lSum + alice(left, mid, prefix), rSum + alice(mid+1, right, prefix)});

        }
        
        return score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> prefix(n);
        prefix[0] = stoneValue[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + stoneValue[i];
        }

        return alice(0, n-1, prefix);

    }
    */


    // Memoization of Approach 1 ...

    /*
    int dp[501][501];

    int alice(int left, int right, vector<int> &prefix) {
        if(left >= right) return 0;

        if(dp[left][right] != -1) return dp[left][right];

        int lSum = 0, rSum = 0;
        int score = 0;

        for(int mid = 0; mid < right; mid++) {
            lSum = prefix[mid] - ((left > 0) ? prefix[left - 1] : 0);  // l .... mid
            rSum = prefix[right] - prefix[mid];  // mid+1 .... right

            if(lSum < rSum) score = max(score, lSum + alice(left, mid, prefix));
            else if(rSum < lSum) score = max(score, rSum + alice(mid+1, right, prefix));
            else score = max({score, lSum + alice(left, mid, prefix), rSum + alice(mid+1, right, prefix)});

        }
        
        return dp[left][right] = score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(dp, -1, sizeof(dp));

        vector<int> prefix(n);
        prefix[0] = stoneValue[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + stoneValue[i];
        }

        return alice(0, n-1, prefix);
    }
    */


    // Approach 3 : Bottom Up approach ( Tabulation ) ...

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();

        vector<int> prefix(n);
        prefix[0] = stoneValue[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + stoneValue[i];
        }

        vector<vector<int>> dp(n+1, vector<int>(n, 0));

        for(int left = n-1; left >= 0; left--) {
            for(int right = left+1; right < n; right++) {

                int score = 0;
                for(int mid = 0; mid < right; mid++) {
                    int lSum = prefix[mid] - ((left > 0) ? prefix[left - 1] : 0);  // l .... mid
                    int rSum = prefix[right] - prefix[mid];  // mid+1 .... right

                    if(lSum < rSum) score = max(score, lSum + dp[left][mid]);
                    else if(rSum < lSum) score = max(score, rSum + dp[mid+1][right]);
                    else score = max({score, lSum + dp[left][mid], rSum + dp[mid+1][right]});

                }

                dp[left][right] = score;
            }
        }

        return dp[0][n-1];
    }
};