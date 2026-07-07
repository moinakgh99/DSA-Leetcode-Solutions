class Solution {
public:
    int maxDepth(string s) {
        
        // // Without Stack
        // int c = 0, maxi = 0;
        // for(char x : s) {
        //     if(x == '(') {
        //         c++;
        //         maxi = max(c, maxi);
        //     }
        //     else if(x == ')') c--;
        // }

        // return maxi;


        // With stack

        stack<char> st;
        int res = 0;

        for(char x : s) {
            if(x == '(') st.push(x);
            else if(x == ')') st.pop();

            res = max(res, (int) st.size());
        }

        return res;
    }
};