class Solution {
public:

    // Approach 1 -> Using Recursion -> gives TLE ....

    /*
    bool alice(int n) {
        if(n == 0) return false;

        for(int k = 1; k * k <= n; k++) {
            if(alice(n - (k * k)) == false) return true;
        }

        return false;
    }

    bool winnerSquareGame(int n) {
        return alice(n);
    }
    */


    // Approach 2 -> Memoization of Approach 1 ( Top down Approach ) ....

    vector<int>dp;
    bool alice(int n) {
        if(n == 0) return false;  // jiski bhi baari aaegi vo dekhaga ye ...

        if(dp[n] != -1) {
            return dp[n] == 1 ? true : false;
        } 
         
            for(int k = 1; k * k <= n; k++) {
                if(alice(n - (k * k)) == false) {  //for bob -> takes turn after n - k^2 ....
                    return dp[n] = true;
                }
            }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n+1, -1);
        return alice(n);  // agar alice jeeta to true vrna false ...
    }
};