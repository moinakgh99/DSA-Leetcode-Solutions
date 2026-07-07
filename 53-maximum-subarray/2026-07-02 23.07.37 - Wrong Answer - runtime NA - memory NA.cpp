class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // O(n2) solution ...
        if(nums.size() == 1) return nums[0];
        int maxSum = 0; 
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};