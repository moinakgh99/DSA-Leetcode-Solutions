class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        
        while(j < t.length()) {
            if(t[j] == s[i]) {
                i++; 
            }
            j++;
        }

        return (i >= s.length()) ? true : false;
    }
};