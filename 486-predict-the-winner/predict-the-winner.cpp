class Solution {
public:

    // Recursive Approach 1 .....

    /*
    int solve(int i, int j, vector<int>& nums) {
        if(i > j) return 0;
        if(i == j) return nums[i];

        // simply diff between player 1 and player 2 ....
        int pick_i = nums[i] - solve(i+1, j, nums);
        int pick_j = nums[j] - solve(i, j-1, nums);

        return max(pick_i, pick_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return solve(0, n-1, nums) >= 0;
    }
    */



    // Memoization of recursive Approach 1 .....
    int dp[23][23];
    int solve(int i, int j, vector<int>& nums) {
        if(i > j) return 0;
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];

        // simply diff between player 1 and player 2 ....
        int pick_i = nums[i] - solve(i+1, j, nums);
        int pick_j = nums[j] - solve(i, j-1, nums);

        return dp[i][j] = max(pick_i, pick_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, n-1, nums) >= 0;
    }
};