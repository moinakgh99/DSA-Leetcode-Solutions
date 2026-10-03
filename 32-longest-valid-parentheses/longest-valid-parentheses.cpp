class Solution {
public:
    int longestValidParentheses(string s) {
        
        // With Stack ...

        /*
        stack<int> st;
        st.push(-1);
        
        int maxLen = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();

                if(st.empty()) st.push(i);
                else {
                    int currLen = i - st.top();
                    maxLen = max(maxLen, currLen);
                }
            }
        }

        return maxLen;
        */

        // Without Stack ....
        int n = s.length();

        int open = 0, close = 0;
        int res = 0;

        // left to right check krenga ....
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) res = max(res, open + close);
            else if(close > open) open = close = 0;
        }

        open = 0, close = 0;

        // right to left check krenga ....
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) res = max(res, open + close);
            else if(open > close) open = close = 0;
        }

        return res;
    }
};