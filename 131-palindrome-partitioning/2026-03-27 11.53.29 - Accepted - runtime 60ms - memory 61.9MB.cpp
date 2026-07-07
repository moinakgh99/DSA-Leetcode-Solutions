class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void fun(int index, string s, vector<string> &path, vector<vector<string>> &ans) {
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                fun(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;

        fun(0, s, path, ans);
        return ans;
    }
};