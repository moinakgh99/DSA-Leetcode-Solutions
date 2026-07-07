class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n - 1, score = 0, maxScore = 0;

        while(i <= j) {

            if(power >= tokens[i]) {
                score++;
                power -= tokens[i];
                i++;
                maxScore = max(score, maxScore);
            }

            else if(score > 0) {
                score--;
                power += tokens[j];
                j--;
            }

            else break;
        }

        return maxScore;
    }
};