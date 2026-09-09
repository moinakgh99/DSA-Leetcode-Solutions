class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;

        // Approach 1 ....

        /*
        long long ans = 0;
        long long lower = 1000;
        long long commas = 1;

        while( lower <= n ) {
            long long upper = (lower * 1000) - 1;

            if(upper > n) upper = n;

            long long numbers = upper - lower + 1;
            ans += (numbers * commas);

            lower *= 1000;
            commas++;
        }

        return ans;
        */


        // Approach 2 ...
        long long ans = 0;
        long long lower = 1000;

        while( lower <= n ) {
            ans += (n - lower + 1);
            lower *= 1000;
        }

        return ans;
    }
};