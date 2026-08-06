class Solution {
public:

    int solve(int n) {

        int mul = 1;
        while(n > 0) {
            int dig = n % 10;
            mul *= dig;
            n /= 10;
        }

        return mul;
    }

    int smallestNumber(int n, int t) {

        int ans = 0;
        while(true) {
            int mul = solve(n);
            if(mul % t == 0) {
                ans = n;
                break;
            }

            n++;
        }

        return ans;
    }
};