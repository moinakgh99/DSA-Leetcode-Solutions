class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<>());

        long long sum = 0;
        int x = min(k, max(0, mul - 1));
        for(int i = 0; i < x; i++) {
            sum += 1LL * nums[i] * (mul - i);
        }

        for(int i = x; i < k; i++) {
            sum += nums[i];
        }

        return sum;
    }
};