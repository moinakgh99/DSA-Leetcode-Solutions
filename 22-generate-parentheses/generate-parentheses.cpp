class Solution {
public:

    bool isValid(string & curr) {
        int c = 0;

        for(char ch : curr) {
            if(ch == '(') c++;
            else c--;
            if(c < 0) return false;
        }

        return (c == 0) ? true : false;
    }

    void solve(string &curr, int n, vector<string> &res) {

        if(curr.length() == 2 * n) {
            if(isValid(curr)) {
                res.push_back(curr);
            }

            return;
        }

        curr.push_back('(');
        solve(curr, n, res);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n, res);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        string curr = "";

        solve(curr, n, res);

        return res;
    }
};