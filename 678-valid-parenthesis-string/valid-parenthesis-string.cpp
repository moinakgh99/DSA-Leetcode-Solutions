class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();

        int mini = 0, maxi = 0;

        for(char ch : s) {
            if(ch == '(') {
                mini++;
                maxi++;
            }

            if(ch == ')') {
                mini--;
                maxi--;
            }

            if(ch == '*') {
                mini--;
                maxi++;
            }

            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }

        return (mini == 0);
    }
};