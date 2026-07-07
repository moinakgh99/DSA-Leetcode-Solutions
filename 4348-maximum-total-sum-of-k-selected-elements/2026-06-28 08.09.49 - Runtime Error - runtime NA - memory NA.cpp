class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<>());

        long long sum = 0;
        for(int i = 0; i < k; i++) {
            sum += max(nums[i] * 1LL, 1LL * (mul * nums[i]));
            mul--;
        }

        return sum;
    }
};