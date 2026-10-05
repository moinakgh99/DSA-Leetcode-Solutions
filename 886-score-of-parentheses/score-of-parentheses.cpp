class Solution {
public:
    int scoreOfParentheses(string s) {
        
        // Approach 1 : Using Stack ...
        stack<int> st;
        st.push(0);

        for(char ch : s) {
            if(ch == '(') {
                st.push(0);
            }
            else {
                int topScore = st.top();
                st.pop();

                int score = 0;
                
                if(topScore == 0) score = 1;
                else score = 2 * topScore;

                st.top() += score;
            }
        }

        return st.top();
    }
};