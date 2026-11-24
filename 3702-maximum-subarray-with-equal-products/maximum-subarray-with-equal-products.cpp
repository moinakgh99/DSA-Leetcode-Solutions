class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;

        for(int i = 0; i < n; i++) {
            long long gcd_ = 0, lcm_ = 1, prod = 1;;
            for(int j = i; j < n; j++) {
                prod *= nums[j];
                gcd_ = gcd(gcd_, nums[j]);
                lcm_ = lcm(lcm_, nums[j]);

                if(prod > gcd_ * lcm_) break;

                if(prod == gcd_ * lcm_) len = max(len, j-i+1);
            }
        }

        return len;
    }
};