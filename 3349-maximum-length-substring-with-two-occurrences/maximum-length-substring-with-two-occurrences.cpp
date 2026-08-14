class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        int ans = 0;
        int i = 0, j = 0;
        unordered_map<int,int> mp;

        while(j < n) {
            mp[s[j]]++;

            while(i < n && mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};