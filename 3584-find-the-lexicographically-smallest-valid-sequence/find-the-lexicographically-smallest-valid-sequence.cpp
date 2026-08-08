class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> matches(n, 0);

        int i = n - 1, j = m - 1;
        int rightMatch = 0;
        while(i >= 0) {
            if(j >= 0 && word1[i] == word2[j]) {
                rightMatch++;
                j--;
            }

            matches[i] = rightMatch;
            i--;
        }

        vector<int> ans;
        bool atMostOne = true;
        i = 0; j = 0;

        while(i < n && j < m) {
            if(word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if(atMostOne == true && i + 1 < n && matches[i+1] >= m - j - 1) {
                ans.push_back(i);
                j++;
                atMostOne = false;
            }

            i++;
        }

        return j == m ? ans : vector<int>();
    }
};