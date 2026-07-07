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

    bool check(int nums, int n) {
        while(n > 0) {
            if(n % 10 == nums) return true;
            n = n/10;
        }
        return false;
    }
    
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size(), s = 0;
        for(int i = 0; i < n; i++) {
            int num = diff(nums[i]);
            if(check(num, nums[i])) {
                s += nums[i];
            }
        }
        return s;
    }
};