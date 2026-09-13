class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> mismatch;

        int i = 0, j = 0;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[j]) mismatch.push_back(i);
            j++;
        }

        if(mismatch.size() == 0) return true;
        else if(mismatch.size() == 2) {
            int first = mismatch[0], second = mismatch[1];

            return (s1[first] == s2[second] && s1[second] == s2[first]);
        }

        return false;
    }
};