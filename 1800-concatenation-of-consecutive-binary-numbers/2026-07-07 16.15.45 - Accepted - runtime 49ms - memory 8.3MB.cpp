class Solution {
public:
    int mod = 1e9+7;
    int concatenatedBinary(int n) {
        
        // Approach 1 .... 
        long long res = 0;
        for(int nums = 1; nums <= n; nums++) {
            int dig = log2(nums) + 1;  // No. of bits required for a Number

            // ab left shift kro, jaga banana k lia nye number k lia jisse append ho jaaye
            res = (((res << dig) % mod) + nums) % mod;
        }

        return res;
    }
};