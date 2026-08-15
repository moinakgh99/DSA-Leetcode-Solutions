class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        bool noZero = false;

        for(int x : nums) {
            ans = (ans ^ x);

            if(x != 0) noZero = true; 
        }

        if(!noZero) return 0;

        return (ans == 0) ? n-1 : n;
    }
};