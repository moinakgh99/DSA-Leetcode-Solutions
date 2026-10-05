class Solution {
public:
    int scoreOfParentheses(string s) {
        
        // Approach 1 : Using Stack ...
        /*
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
        */


        // Approach 2 : Using Vector ....
        int n = s.length();

        vector<int> vec;
        int score = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                vec.push_back(score);
                score = 0;
            }
            else {
                if(s[i - 1] == '(') score = vec.back() + 1;
                else score = vec.back() + ( 2 * score );
                vec.pop_back();
            }
        }

        return score;
    }
};