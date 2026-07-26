class Solution {
public:
    int largestInteger(int n, int s) {
        if(s == 0) return 0;
        if(s > 9 * n) return -1;

        int res = 0;
        while(n--) {
            int dig = min(9, s);
            res = 10 * res + dig;
            s -= dig;
        }

        return res;
    }
};