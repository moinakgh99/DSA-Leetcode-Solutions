class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();

        stack<int> st;
        string res = "";

        for(char ch : s) {
            if(ch == '(') st.push(res.length());
            else if(ch == ')') {
                int len = st.top();
                st.pop();
                reverse(res.begin() + len, res.end());
            }
            else res += ch;
        }

        return res;
    }
};