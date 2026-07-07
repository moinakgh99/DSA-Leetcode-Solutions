class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        // O(n2) gives TLE
        // int maxSum = -1;
        // for(int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for(int j = i + 1; j < n; j++) {
        //         if((j- i) >= k) {
        //             sum = nums[i] + nums[j];
        //             maxSum = max(maxSum, sum);
        //         }
        //     }
        // }
        // return maxSum;

        int sum = 0, res = -1, l = INT_MIN;
        for(int j = k; j < n; j++) {
            int i = j - k;
            l = max(l, nums[i]);
            sum = l + nums[j];
            res = max(res, sum);
        }
        return res;
    }
};