class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<bool> visited(26, false);
        vector<int> lastIdx(26);
        string res = "";

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            lastIdx[ch - 'a'] = i;
        }

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            if(visited[ch - 'a'] == true) continue;

            while(res.size() > 0 && res.back() > ch && lastIdx[res.back() - 'a'] > i) {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }

            res += ch;
            visited[ch - 'a'] = true;
        }

        return res;
    }
};