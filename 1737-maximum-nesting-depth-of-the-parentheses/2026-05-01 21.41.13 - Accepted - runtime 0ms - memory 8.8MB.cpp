class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;

        int c = 0, maxi = 0;
        for(int x : s) {
            if(x == '(') {
                st.push(')');
                c++;
                maxi = max(c, maxi);
            }
            else if(x == ')') c--;
        }

        return maxi;
    }
};