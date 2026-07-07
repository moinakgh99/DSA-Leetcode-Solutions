class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mpS;
        unordered_map<char,int> mpT;

        for(char c : s) mpS[c]++;
        for(char t : target) mpT[t]++;

        int mini = INT_MAX;
        for(auto &m : mpT) {
            mini = min(mini, mpS[m.first] / m.second);
        }

        return mini;
    }
};