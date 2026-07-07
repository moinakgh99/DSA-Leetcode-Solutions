class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = s.size();
        int n = g.size();

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(s[j] >= g[i]) i++;
            j++;
        }
        return i;   
    }
};