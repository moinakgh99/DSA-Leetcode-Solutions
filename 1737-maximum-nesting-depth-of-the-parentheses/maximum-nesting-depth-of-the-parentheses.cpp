class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();

        int c = 0, depth = 0;
        for(char ch : s) {
            if(ch == '(') {
                c++;
                depth = max(depth, c);
            }
            else if(ch == ')') c--;
        }

        return depth;
    }
};