class Solution {
public:
    // int f(int idx, vector<int> &nums, vector<int> &dp) {
    //     if(idx == 0) return nums[0];
    //     if(idx < 0) return 0;

    //     if(dp[idx] != -1) return dp[idx];

    //     int pick = nums[idx] + f(idx - 2, nums, dp);
    //     int nonPick = f(idx - 1, nums, dp);
    //     return dp[idx] = max(pick, nonPick);
    // }


    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return f(n-1, nums, dp);

        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int pick = nums[i];
            if(i > 1) pick += prev2;

            int nonPick = 0 + prev;
            int curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};