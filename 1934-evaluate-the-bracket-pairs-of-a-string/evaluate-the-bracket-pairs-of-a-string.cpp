class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string, string> mp;

        for(auto &s : knowledge) mp[s[0]] = s[1];

        string res = "", temp = "";
        int i = 0;
        bool bracket = false;
        while(i < n) {
            if(s[i] == '(') bracket = true;
            else if(s[i] == ')') {
                res += mp.count(temp) ? mp[temp] : "?";
                bracket = false;
                temp = "";
            }
            else if(bracket) temp += s[i];
            else res += s[i];

            i++;
        }

        return res;
    }
};