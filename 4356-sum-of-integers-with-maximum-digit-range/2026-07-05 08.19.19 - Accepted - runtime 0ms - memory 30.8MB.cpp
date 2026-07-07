class Solution {
public:

    int diff(int n) {
        int mini = INT_MAX, maxi = INT_MIN;
        while(n > 0) {
            int dig = n % 10;
            mini = min(mini, dig);
            maxi = max(maxi, dig);
            n = n/10;
        }
        return maxi - mini;
    }
    
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size(), d = 0;
        for(int x : nums) {
            d = max(d, diff(x));
        }

        int res = 0;

        for(int x : nums) {
            if(diff(x) == d) res += x;
        }
        return res;
    }
};