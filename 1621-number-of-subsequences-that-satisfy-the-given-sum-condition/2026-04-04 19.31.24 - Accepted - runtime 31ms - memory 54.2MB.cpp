class Solution {
public:
    int M = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int res = 0;

        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;
        for(int k = 1; k < n; k++) {
            power[k] = (power[k-1] * 2) % M;
        }

        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                res = res % M + power[j-i];
                i++;
            } else j--;
        } 
        return res;
    }
};