class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int apply, string &s, string &t) {
        if(i == n) return true;
        if(j == m) return false;

        if(dp[i][j][apply] != -1) {
            return dp[i][j][apply];
        }

        bool res = false;

        if(s[i] == t[j]) res |= solve(i+1, j+1, apply, s,t);

        res |= solve(i, j+1, apply, s,t);

        if(!apply) res |= solve(i+1, j+1, 1, s,t);

        return dp[i][j][apply] = res;
    }
    
    bool canMakeSubsequence(string s, string t) {
        n = s.length(), m = t.length();
        dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(2, -1)));
        return solve(0,0,0,s,t);
    }
};