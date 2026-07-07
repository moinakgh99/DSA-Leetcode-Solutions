class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int first = 0, sec = 0;
        for(auto &c : tokens) {
            if(c == "+") {
                sec = st.top();
                st.pop();
                first = st.top();
                st.pop();
                st.push(first + sec);
            }
            else if(c == "-") {
                sec = st.top();
                st.pop();
                first = st.top();
                st.pop();
                st.push(first - sec);
            }
            else if(c == "*") {
                sec = st.top();
                st.pop();
                first = st.top();
                st.pop();
                st.push(first * sec);
            }
            else if(c == "/") {
                sec = st.top();
                st.pop();
                first = st.top();
                st.pop();
                st.push(first / sec);
            }
            else {
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};