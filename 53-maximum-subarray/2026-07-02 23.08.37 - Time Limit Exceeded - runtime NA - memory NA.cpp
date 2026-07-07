class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // O(n2) solution ...
        int maxSum = INT_MIN; 
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