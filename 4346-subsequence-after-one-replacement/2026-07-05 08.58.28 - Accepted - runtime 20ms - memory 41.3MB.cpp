class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> p(n+1, 0);
        {
            int j = 0;
            for(int i = 0; i < n; i++) {
                while(j < m && t[j] != s[i]) j++;
                if(j < m) {
                    p[i + 1] = j + 1;
                    j++;
                }
                else {
                    for(int k = i + 1; k <= n; k++) p[k] = m + 1;
                    break;
                }
            }
        }

        vector<int> sf(n+1, -1);
        sf[n] = m;
        {
            int j = m - 1;
            for(int i = n - 1; i >= 0; i--) {
                while(j >= 0 && t[j] != s[i]) j--;
                if(j >= 0) {
                    sf[i] = j;
                    j--;
                }
                else {
                    for(int k = i; k >= 0; k--) sf[k] = -1;
                    break;
                }
            }
        }

        if(p[n] <= m) return true;

        for(int i = 0; i < n; i++) {
            if(p[i] < m && sf[i + 1] != -1 && p[i] + 1 <= sf[i+1]) return true;
        }
        return false;
    }
};