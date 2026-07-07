class Solution {
public:

    bool isValid(long long s, int x) {
        if(s % 10 != x) return false;
        while(s >= 10) {
            s /= 10;
        }
        return s == x;
    }
    
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int res = 0;

        for(int i = 0; i < n; i++) {
            long long s = 0;
            for(int j = i; j < n; j++) {
                s += nums[j];
                if(isValid(s,x)) res++;
            }
        }
        return res;
    }
};