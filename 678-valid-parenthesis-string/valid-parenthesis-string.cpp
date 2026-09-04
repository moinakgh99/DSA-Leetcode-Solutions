class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, mxi = 0;

        for(char ch : s) {
            if(ch == '(') {
                mini++;
                mxi++;
            }
            else if(ch == ')') {
                mini--;
                mxi--;
            }
            else { // agar * hua to !!!
                mini--;
                mxi++;
            }

            if(mini < 0) mini = 0;
            if(mxi < 0) return false;
        }

        return (mini == 0);
    }
};