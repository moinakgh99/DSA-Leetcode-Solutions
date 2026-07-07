class Solution {
public:

    int findWaviness(int i) {
        int score = 0;
        string s = to_string(i);

        if(s.length() < 3) return 0;

        for(int x = 1; x <= s.length() - 2; x++) {
            if(s[x] > s[x - 1] && s[x] > s[x + 1]) score++;
            if(s[x] < s[x - 1] && s[x] < s[x + 1]) score++;
        }
        return score;
    }

    int totalWaviness(int num1, int num2) {
        int score = 0;
        for(int i = num1; i <= num2; i++) {
            score += findWaviness(i);
        }
        return score;
    }
};