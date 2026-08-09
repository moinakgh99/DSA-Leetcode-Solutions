class Solution {
public:

    // Approach 1 -> Using recursion .... Gives TLE ...

    /*
    int n;

    int alice(int person, int idx, int m, vector<int> &piles) {
        if(idx >= n) return 0;

        int stones = 0;
        int ans = (person == 1) ? INT_MIN : INT_MAX;

        for(int x = 1; x <= min(2 * m, n - idx); x++) {
            stones += piles[idx + x - 1];

            if(person == 1) {   // for alice
                ans = max(ans, stones + alice(0, idx + x, max(m, x), piles));   // need max for alice , so we add stones as well
            }
            else {   // if bob -> takes minimum
                ans = min(ans, alice(1, idx + x, max(m, x), piles));
            }
        }

        return ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        return alice(1, 0, 1, piles);  // parameters -> person, idx, M, array ..... 1 -> alice and 0 -> bob
    }
    */


    // Approach 2 -> Using Memoization of Approach 1 ... ( Optimal Appproach )
    int n;
    int dp[2][101][101];

    int alice(int person, int idx, int m, vector<int> &piles) {
        if(idx >= n) return 0;

        if(dp[person][idx][m] != -1) return dp[person][idx][m]; 

        int stones = 0;
        int ans = (person == 1) ? INT_MIN : INT_MAX;

        for(int x = 1; x <= min(2 * m, n - idx); x++) {
            stones += piles[idx + x - 1];

            if(person == 1) {   // for alice
                ans = max(ans, stones + alice(0, idx + x, max(m, x), piles));   // need max for alice , so we add stones as well
            }
            else {   // if bob -> takes minimum
                ans = min(ans, alice(1, idx + x, max(m, x), piles));
            }
        }

        return dp[person][idx][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));

        return alice(1, 0, 1, piles);  // parameters -> person, idx, M, array ..... 1 -> alice and 0 -> bob
    }
};