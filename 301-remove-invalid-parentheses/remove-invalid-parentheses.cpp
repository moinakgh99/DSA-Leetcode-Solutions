class Solution {
private:
    unordered_set<string> answer;

    void solve(string& s, int index, int leftRemove, int rightRemove, int balance, string& current) {

        if(index == s.length()) {
            if(leftRemove == 0 && rightRemove == 0 && balance == 0) {
                answer.insert(current);
            }
            return;
        }

        char ch = s[index];

        if(ch == '(') {

            if(leftRemove > 0) {
                solve(s, index + 1, leftRemove - 1, rightRemove, balance, current);
            }

            current.push_back(ch);

            solve(s, index + 1, leftRemove, rightRemove, balance + 1, current);

            current.pop_back();
        }

        else if(ch == ')') {

            if(rightRemove > 0) {
                solve(s, index + 1, leftRemove, rightRemove - 1, balance, current);
            }

            if(balance > 0) {
                current.push_back(ch);

                solve(s, index + 1, leftRemove, rightRemove, balance - 1, current);

                current.pop_back();
            }
        }

        else {
            current.push_back(ch);

            solve(s, index + 1, leftRemove, rightRemove, balance, current);

            current.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        for(char ch : s) {
            if(ch == '(') {
                leftRemove++;
            }
            else if(ch == ')') {
                if(leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string current;

        solve(s, 0, leftRemove, rightRemove, 0, current);

        return vector<string>(answer.begin(), answer.end());
    }
};