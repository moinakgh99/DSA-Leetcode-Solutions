class Solution {
public:
    int maxDepth(string s) {

        int c = 0, maxi = 0;
        for(char x : s) {
            if(x == '(') {
                c++;
                maxi = max(c, maxi);
            }
            else if(x == ')') c--;
        }

        return maxi;
    }
};