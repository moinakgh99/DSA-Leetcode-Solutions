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

    /*
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
    */



    // Recursive Approach 2 ....
    int solve(int i, int j, vector<int>& nums) {
        if(i > j) return 0;
        if(i == j) return nums[i];

        /* 
            simply player 1 ko dekh k chlo, ignore player 2 now, vo sbse pehle apna best choose krega, 
            then min dekhega jb player 1 ki dubara turn aaega , coz player 2 tb tk apna best choose
            kr chuka hoga !!!
        */
        int pick_i = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));
        int pick_j = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));

        return max(pick_i, pick_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = 0;

        for(int i = 0; i < n; i++) {
            total_score += nums[i];
        }

        int player1_score = solve(0, n-1, nums);
        int player2_score = total_score - player1_score;

        return player1_score >= player2_score;
    }
};