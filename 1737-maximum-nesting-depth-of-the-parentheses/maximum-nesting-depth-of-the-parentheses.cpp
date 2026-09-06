class Solution {
public:
    int maxDepth(string s) {
        int c = 0;
        int depth = 0;

        if(s.size() == 1) return 0;

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