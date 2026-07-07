class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();

        string temp1 = "", temp2 = "";

        for(int i = 0; i < m; i++) {
            temp1 += word1[i];
        }
        for(int j = 0; j < n; j++) {
            temp2 += word2[j];
        }

        return temp1 == temp2;
    }
};