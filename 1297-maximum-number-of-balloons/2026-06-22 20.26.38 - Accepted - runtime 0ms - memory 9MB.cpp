class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string res = "balloon";
        unordered_map<char, int> mpT;
        unordered_map<char, int> mpR;

        for(char t : text) mpT[t]++;
        for(char r : res) mpR[r]++;

        int mini = INT_MAX;
        for(auto &m : mpR) {
            mini = min(mini, mpT[m.first] / m.second);
        }

        return mini;
    }
};