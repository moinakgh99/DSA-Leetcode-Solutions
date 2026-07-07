class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int maxSum = -1;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i + 1; j < n; j++) {
                if((j- i) >= k) {
                    sum = nums[i] + nums[j];
                    maxSum = max(maxSum, sum);
                }
            }
        }
        return maxSum;
    }
};